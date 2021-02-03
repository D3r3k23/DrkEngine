
#include "Chess.h"


namespace Drk::Chess
{
    Rank& operator++(Rank& rank)
    {
        if (rank != R8)
            rank = (Rank)((int)rank + 1);

        return rank;
    }

    
    File& operator++(File& file)
    {
        if (file != FH)
            file = (File)((int)file + 1);

        return file;
    }


    Board::Board()
    {
        for (Rank rank = R1; rank <= R8; rank++)
            for (File file = FA; file <= FH; file++)
                board[rank][file] = { rank, file, None };

        load_position("DrkEngine/resources/starting_position.drk");
    }

    void Board::load_position(const char* fn)
    {
        std::ifstream iFile(fn, std::ifstream::in);

        ASSERT(!iFile.fail(), "Could not load starting position.");
    }
}
