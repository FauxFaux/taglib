#include "tfile.h"

using TagLib::FileAccessor;
using TagLib::FileName;
using TagLib::FileNameHandle;

class FSFileAccessor : public FileAccessor
{
private:
  FILE *file;
  FileName name_;
  bool readOnly_;
public:
  FSFileAccessor(FileName fn);
  ~FSFileAccessor();
  bool isOpen() const { return file == 0; }
  size_t fread(void *dst, size_t element_size, size_t count) const;
  size_t fwrite(const void *s, size_t siz, size_t count);
  int fseek(long offset, int origin);
  void clearError();
  long tell() const;
  int truncate(long size);
  FileNameHandle name() const;
  bool readOnly() const;
};
