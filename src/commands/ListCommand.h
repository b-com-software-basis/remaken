/**
 * @copyright Copyright (c) 2019 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Loïc Touraine
 *
 * @file
 * @brief description of file
 * @date 2019-11-15
 */

#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H

#include "AbstractCommand.h"
#include "CmdOptions.h"

class ListCommand : public AbstractCommand
{
public:
    ListCommand(const CmdOptions & options);
    int execute() override;
    static constexpr const char * NAME="list";

private:
    int listPackages();
    int listPackageVersions(const std::string & pkgName);
    int listPackageFiles(const std::string & pkgName, const std::string & pkgVersion);
    const CmdOptions & m_options;
};

#endif // LISTCOMMAND_H
