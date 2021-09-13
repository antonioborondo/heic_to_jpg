#include <libheif/heif.h>

#include <iostream>

int main()
{
    std::cout << "Hello world!" << std::endl;

    uint8_t magic[12];
    enum heif_filetype_result filetype_check = heif_check_filetype(magic, 12);

 struct heif_context* ctx = heif_context_alloc();
  if (!ctx) {
    fprintf(stderr, "Could not create context object\n");
    return 1;
  }

    return 0;
}
