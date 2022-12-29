#ifndef WAVE_HEADER_H
#define WAVE_HEADER_H

#include "chunk.h"

#include <array>


namespace dr_calculator {

struct wave
{
    master_chunk MasterChunk;

    wave()
    {
        MasterChunk.WaveId = std::array<char, 4>{};
    }

    //The arrays for CkId and CkSize might not contain char at some
    // point so would be nice to report size as lowest common denominator - bytes in this case
    const std::size_t total_size() const
    {
        return      MasterChunk.size_of_chunk_bytes()
                +   MasterChunk.CkId.size()
                +   MasterChunk.CkSize.size();
    }

};

}

#endif //WAVE_HEADER_H
