#include "ProfileCommand.h"
#include "managers/DependencyManager.h"
#include <boost/filesystem/detail/utf8_codecvt_facet.hpp>
#include "utils/PathBuilder.h"
#include "retrievers/HttpFileRetriever.h"
#include "utils/OsUtils.h"
#include <boost/log/trivial.hpp>

ProfileCommand::ProfileCommand(const CmdOptions & options):AbstractCommand(ProfileCommand::NAME),m_options(options)
{
}

int ProfileCommand::execute()
{
    auto subCommand = m_options.getSubcommand();
    if (subCommand == "display") {
        m_options.displayConfigurationSettings();
        return 0;
    }
    if (subCommand == "init") {
        m_options.writeConfigurationFile();
        return 0;
    }
    return 0;
}
