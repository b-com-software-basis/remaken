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

#ifndef CREDENTIALSFILERETRIEVER_H
#define CREDENTIALSFILERETRIEVER_H
#include <string>
#include "Constants.h"
#include "CmdOptions.h"
#include "HttpFileRetriever.h"
#include <boost/beast/http.hpp>

class CredentialsFileRetriever : public HttpFileRetriever
{
public:
    CredentialsFileRetriever(const CmdOptions & options);
    ~CredentialsFileRetriever() override = default;
    fs::path retrieveArtefact(const std::string & url) override;

private:
    boost::beast::http::status downloadArtefact (const std::string & source,const fs::path & dest, std::string & newLocation);

    std::string m_apiKey = "";

};

#endif // CREDENTIALSFILERETRIEVER_H
