#include <exception>
#include <iostream>
#include <sstream>
#include "File.h"

File::File(std::ios::iostate ifs_except, std::ios::iostate ofs_except)
  : ifs_(), ofs_() {

  ifs_.exceptions(ifs_except);
  ofs_.exceptions(ofs_except);
}

File::~File() {
}

#if CXXSTD >= 17
void File::Copy(const std::string &ifile, const std::string &ofile) noexcept(false) {
#else
void File::Copy(const std::string &ifile, const std::string &ofile) throw(std::ios::failure) {
#endif
  debug_("before open...");
  ifs_.open(ifile);
  ofs_.open(ofile);
  debug_("after open...");

  const int buffer_len = 0xff;
  char buffer[buffer_len];

  debug_("before read & write...");
  while (ifs_.good()) {
    debug_("before ifs read...");
    try {
      ifs_.read(buffer, sizeof(buffer)); // Read at most n bytes into
    } catch (std::exception &e) {
      if (!ifs_.eof()) {
        throw e;
      }
    }
    debug_("after ifs read...");
    std::stringstream ss;
    ss << "ifs_.gcount()=" << ifs_.gcount();
    debug_(ss.str());
    debug_("before ofs write...");
    ofs_.write(buffer, ifs_.gcount()); // buf, then write the buf to
    debug_("after ofs write...");
  }
  debug_("after read & write...");

  // Check streams for problems...
  debug_("before close...");
  ifs_.close();
  ofs_.close();
  debug_("after close...");
  return;
}
