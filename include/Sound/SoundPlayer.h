#pragma once
#include <ao/ao.h>
#include <mpg123.h>

class SoundPlayer {
    public:
        SoundPlayer();
        void Init();
        void PlayFrame();
        static void* send_wrapper(void* object);
    private:
        ao_device *dev;
        ao_sample_format format;
        mpg123_handle *mh;
        int driver;
        unsigned char *buffer;
        size_t done;
        size_t buffer_size;
        int channels, encoding;
        long rate;
};