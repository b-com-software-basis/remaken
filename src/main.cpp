#include <iostream>
#include "Constants.h"
#include "CmdOptions.h"
#include "commands/InfoCommand.h"
#include "commands/InitCommand.h"
#include "commands/InstallCommand.h"
#include "commands/ListCommand.h"
#include "commands/ParseCommand.h"
#include "commands/PackageCommand.h"
#include "commands/BundleCommand.h"
#include "commands/ConfigureCommand.h"
#include "commands/CleanCommand.h"
#include "commands/BundleXpcfCommand.h"
#include "commands/VersionCommand.h"
#include "commands/ProfileCommand.h"
#include "commands/RemoteCommand.h"
#include "commands/RunCommand.h"
#include "commands/SearchCommand.h"
#include <memory>

using namespace std;

int main(int argc, char** argv)
{
    map<string,shared_ptr<AbstractCommand>> dispatcher;

    CmdOptions opts;
    try {
        if (auto result = opts.parseArguments(argc,argv); result != CmdOptions::OptionResult::RESULT_SUCCESS ) {
            return static_cast<int>(result);
        }
        dispatcher["clean"] = make_shared<CleanCommand>(opts);
        dispatcher["configure"] = make_shared<ConfigureCommand>(opts);
        dispatcher["init"] = make_shared<InitCommand>(opts);
        dispatcher["info"] = make_shared<InfoCommand>(opts);
        dispatcher["install"] = make_shared<InstallCommand>(opts);
        dispatcher["list"] = make_shared<ListCommand>(opts);
        dispatcher["run"] = make_shared<RunCommand>(opts);
        dispatcher["parse"] = make_shared<ParseCommand>(opts);
        dispatcher["package"] = make_shared<PackageCommand>(opts);
        dispatcher["bundle"] = make_shared<BundleCommand>(opts);
        dispatcher["bundleXpcf"] = make_shared<BundleXpcfCommand>(opts);
        dispatcher["profile"] = make_shared<ProfileCommand>(opts);
        dispatcher["remote"] = make_shared<RemoteCommand>(opts);
        dispatcher["search"] = make_shared<SearchCommand>(opts);
        dispatcher["version"] = make_shared<VersionCommand>();
        if (mapContains(dispatcher, opts.getAction())) {
            return dispatcher.at(opts.getAction())->execute();
        }
        else {
            return -1;
        }
        return 0;
    }
    catch (std::runtime_error & e) {
        std::cout << "ERROR: "<<e.what() << std::endl;
        opts.printUsage();
    }
    return -1;
}
