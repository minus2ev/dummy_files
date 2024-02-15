#pragma once

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <fstream>
#include <sstream>
#include <iomanip>
#include "openssl/md5.h"

using namespace std;

namespace { // anonymous
constexpr size_t buf_size = 1 << 20; // 1Mb
}

string fmd5(ifstream& file)
{
    if (!file || !file.is_open())
    {
        return "";
    }
    try {
        file.seekg(0, file.end);
        const size_t flen = file.tellg();
        file.seekg(0, file.beg);

        unique_ptr<char[]> buf = make_unique<char[]>(buf_size);
        int pos = 0;
        int read_size = buf_size;
        MD5_CTX ctx;
        MD5_Init(&ctx);

        while (pos < flen) {
            if (flen - pos < buf_size)
            {
                read_size = flen - pos;
            }
            file.read(buf.get(), read_size);
            MD5_Update(&ctx, buf.get(), read_size);
            pos += read_size;
        }
        ostringstream res{};
        unsigned char byte_res[MD5_LBLOCK];
        MD5_Final(byte_res, &ctx);
        for (int i = 0; i < MD5_LBLOCK; ++i)
        {
            res << hex << setw(2) << setfill('0') << static_cast<int>(byte_res[i]);
        }
        return res.str();
    }
    catch (...)
    {
        return "";
    }
}