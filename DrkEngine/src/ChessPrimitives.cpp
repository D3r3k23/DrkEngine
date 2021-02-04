
#include "ChessPrimitives.h"


namespace Drk::Chess
{
    Rank operator+(const Rank& rank, int n)
    {
        int nRank = (int)rank;
        nRank += n;
        
        if (nRank > (int)R8)
            return R8;
        else
            return (Rank)nRank;
    }

    Rank operator-(const Rank& rank, int n)
    {
        int nRank = (int)rank;
        nRank -= n;
        
        if (nRank < (int)R1)
            return R1;
        else
            return (Rank)nRank;
    }

    File operator+(const File& file, int n)
    {
        int nFile = (int)file;
        nFile += n;
        
        if (nFile > (int)R8)
            return Fh;
        else
            return (File)nFile;
    }

    File operator-(const File& file, int n)
    {
        int nFile = (int)file;
        nFile -= n;
        
        if (nFile < (int)R1)
            return Fa;
        else
            return (File)nFile;
    }


    std::string Move::to_str()
    {
        return "";
    }
}
