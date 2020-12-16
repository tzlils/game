#include <Sound/SoundPlayer.h>
#define ALSA_PCM_NEW_HM_PARAMS_API
#include <ao/ao.h>
#include <mpg123.h>

SoundPlayer::SoundPlayer() {

}


void SoundPlayer::Init() {    
    ao_initialize();
    driver = ao_default_driver_id();
    mpg123_init();
    mh = mpg123_new(NULL, NULL);
    buffer_size = mpg123_outblock(mh);
    buffer = (unsigned char*) malloc(buffer_size*sizeof(unsigned char));

    mpg123_open(mh, "assets/song.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    format.bits = mpg123_encsize(encoding) * 8;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;

    dev = ao_open_live(driver, &format, NULL);
}

void* SoundPlayer::send_wrapper(void* object) {
    reinterpret_cast<SoundPlayer*>(object)->PlayFrame();
    return 0;
}

void SoundPlayer::PlayFrame() {
    int v = mpg123_read(mh, buffer, buffer_size, &done);
    ao_play(dev, (char*)buffer, done);

    if(v != MPG123_OK) {
        free(buffer);
        ao_close(dev);
        mpg123_close(mh);
        mpg123_delete(mh);
        mpg123_exit();
        ao_shutdown();
    }
}