#ifndef FILE_H_
#define FILE_H_

#include <fstream>
#include <string>

#ifdef DEBUG
#define debug_(msg) \
  std::cerr << __DATE__ << " " << __TIME__ << " " \
            << "msg=\"" << msg << "\" " \
            << "at line: " << __LINE__ << " " \
            << "file: " << __FILE__ << std::endl
#else
#define debug_(msg)
#endif

class File {
  public:
    // constructor/copy constructor/destructor
    // フラグ 内容
    // eofbit ファイルの終端に達した
    // failbit 内部動作が原因で入力操作が失敗した← open/close に失敗すると立つ
    //  バッファを使い切らずに読み終わっても立つ
    // badbit ストリームバッファの入出力操作が失敗した
    // goodbit エラーなし（値としてはゼロ）
    // std::ios::fail() と等価 std::ios::failbit | std::ios::badbit
    // std::ios::bad() と等価 std::ios::badbit
    File(std::ios::iostate ifs_except = std::ios::failbit | std::ios::badbit, std::ios::iostate ofs_except = std::ios::failbit | std::ios::badbit);
    ~File();
  public:
    // void Copy(const std::string &ifile, const std::string &ofile)
    // throw (std::ios::failure) {
    // 動的例外仕様はC++11で非推奨この書き方はC++17では削除
    // C++11で導入されたnoexcept例外仕様を使用したコード。
    // noexceptおよびnoexcept(true)は、「この関数からは例外を送出しない」という宣言。
    // noexcept(false)およびnoexceptを付けないことは「この関数からは例外を送出する可能性がある」という宣言。
    // void f() noexcept;
    // void f() noexcept(true);
    // void f() noexcept(false);
    // void f();
    // void Copy(const std::string &ifile,
    //           const std::string &ofile) noexcept(false);
    // void Copy(const std::string &ifile, const std::string &ofile) throw(std::ios::failure);
#if CXXSTD >= 17
    void Copy(const std::string &ifile, const std::string &ofile) noexcept(false);
#else
    void Copy(const std::string &ifile, const std::string &ofile) throw(std::ios::failure);
#endif

  private:
    // data members
    std::ifstream ifs_;
    std::ofstream ofs_;
};

#endif // FILE_H_
