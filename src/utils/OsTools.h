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

#ifndef OSTOOLS_H
#define OSTOOLS_H

#include "CmdOptions.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class OsTools
{
public:
    OsTools() = delete;
    ~OsTools() = delete;
    static bool isElevated();
    static void copySharedLibraries(const fs::path & sourceRootFolder, const CmdOptions & options);
    static const std::string_view & sharedSuffix(const std::string_view & osStr);
};

#endif // OSTOOLS_H
