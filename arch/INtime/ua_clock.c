#ifdef UA_ARCHITECTURE_INTIME

#include <open62541/types.h>
#include <time.h>
#include <sys/time.h>

inline  UA_DateTime
UA_DateTime_now(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * UA_DATETIME_SEC) + (tv.tv_usec * UA_DATETIME_USEC) +
           UA_DATETIME_UNIX_EPOCH;
}

/* Credit to https://stackoverflow.com/questions/13804095/get-the-time-zone-gmt-offset-in-c */
inline UA_Int64
UA_DateTime_localTimeUtcOffset(void) {
    time_t gmt, rawtime = time(NULL);

    struct tm ptm;
    gmtime_s(&rawtime, &ptm);
    // Request that mktime() looksup dst in timezone database
    ptm.tm_isdst = -1;
    gmt = mktime(&ptm);

    return (UA_Int64) (difftime(rawtime, gmt) * UA_DATETIME_SEC);
}

inline UA_DateTime
UA_DateTime_nowMonotonic(void) {
    LARGE_INTEGER freq, ticks;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&ticks);
    UA_Double ticks2dt = UA_DATETIME_SEC / (UA_Double)freq.QuadPart;
    return (UA_DateTime)(ticks.QuadPart * ticks2dt);
}

#endif /* UA_ARCHITECTURE_INTIME */
