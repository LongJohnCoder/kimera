#ifndef CONFIG_H
#define CONFIG_H

#include <libavcodec/avcodec.h>
#include <signal.h>

//
// Default Settings
//

#define HEADER_SIZE         12
#define NO_PTS              UINT64_C(-1)

#define DEFAULT_PORT        8080
#define DEFAULT_ADDRESS     "0.0.0.0"
#define DEFAULT_LOOPBACK    "/dev/video2"

#define DEFAULT_FRAMERATE   30
#define DEFAULT_WIDTH       1280
#define DEFAULT_HEIGHT      720
#define DEFAULT_BITRATE     3000000
#define DEFAULT_CODEC       "libx265"
#define DEFAULT_FORMAT      AV_PIX_FMT_YUV420P

//
// Variables
//

volatile sig_atomic_t stop;

typedef enum {
    UNIX     = 1 << 0,
    TCP      = 1 << 1,
    STDOUT   = 1 << 2,
    DISPLAY  = 1 << 3,
    LOOPBACK = 1 << 4
} Interfaces;

typedef enum {
    TRANSMITTER = 1 << 0,
    RECEIVER    = 1 << 1
} Mode;

typedef struct {
    int width;
    int height;
    char* codec;
    int bitrate;
    int framerate;
    int frame_size;
    int port;
    char* address;
    char* loopback;
    Mode mode;
    Interfaces sink;
    Interfaces source;
    enum AVPixelFormat in_format;
    enum AVPixelFormat out_format;
} State;

#endif
