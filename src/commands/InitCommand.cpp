#include "InitCommand.h"
#include "managers/DependencyManager.h"
#include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
#include "utils/PathBuilder.h"
#include "retrievers/HttpFileRetriever.h"
#include "utils/OsTools.h"
#include <boost/log/trivial.hpp>

InitCommand::InitCommand(const CmdOptions & options):AbstractCommand(InitCommand::NAME),m_options(options)
{
}

fs::path installArtefact(const CmdOptions & options, const std::string & source, const fs::path & outputDirectory, const std::string & name = "" )
{
    auto fileRetriever = std::make_shared<HttpFileRetriever>(options);
    fs::detail::utf8_codecvt_facet utf8;
    fs::path compressedDependency = fileRetriever->retrieveArtefact(source);
    if (!fs::exists(outputDirectory)) {
        fs::create_directories(outputDirectory);
    }
    std::shared_ptr<ZipTool> zipTool = ZipTool::createZipTool(options);
    int result = zipTool->uncompressArtefact(compressedDependency,outputDirectory);
    if (result != 0) {
        throw std::runtime_error("Error uncompressing artefact " + source);
    }
    fs::remove(compressedDependency);
    for (fs::directory_entry& x : fs::directory_iterator(outputDirectory)) {
        if (fs::is_directory(x.path())) {
            return x.path();
        }
    }
    return fs::path();
}

int InitCommand::execute()
{
    fs::detail::utf8_codecvt_facet utf8;
    fs::path remakenRootPath = PathBuilder::getHomePath() / Constants::REMAKEN_FOLDER;
    fs::path remakenRulesPath = remakenRootPath / "rules";
    fs::path remakenProfilesPath = remakenRootPath / Constants::REMAKEN_PROFILES_FOLDER;
    fs::path qmakeRootPath = remakenRulesPath / "qmake";

    auto linkStatus = boost::filesystem::symlink_status(qmakeRootPath);
    if (!fs::exists(remakenProfilesPath)) {
        fs::create_directories(remakenProfilesPath);
    }
    if (m_options.force()) {
        fs::remove(qmakeRootPath);
    }
    else if (linkStatus.type() != fs::file_not_found || fs::exists(qmakeRootPath)) {
        BOOST_LOG_TRIVIAL(info)<<"qmake rules already installed ! skipping...";
        return 0;
    }
    if (!fs::exists(remakenRulesPath)) {
        fs::create_directories(remakenRulesPath);
    }
    std::string source="https://github.com/b-com-software-basis/builddefs-qmake/releases/download/";
    std::string release = m_options.getQmakeRulesTag();
    if (release == "latest") {
        release = "builddefs-qmake-latest";
    }
    source += release;
    source += "/builddefs-qmake-package.zip";
    BOOST_LOG_TRIVIAL(info)<<"Installing qmake rules version ["<<release<<"]";
    fs::path artefactFolder = installArtefact(m_options,source,remakenRulesPath);

    if (fs::exists(artefactFolder)) {
        fs::create_symlink(artefactFolder.filename(),qmakeRootPath);
    }
    return 0;
}
