#include "Constants.h"

bool copy_file_overwrite(fs::path const& from, fs::path const& to, boost::system::error_code* ec)
{
    #if BOOST_VERSION >= 107400
        fs::copy_file(from , to, fs::copy_options::overwrite_existing);
    #else /* BOOST_VERSION */
        fs::copy_file(from , to, fs::copy_option::overwrite_if_exists);
    #endif /* BOOST_VERSION */
}

