
#include "ChessPrimitives.hpp"


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

    Rank& operator+=(Rank& rank, int x) { rank = rank + x;  return rank; }
    Rank& operator-=(Rank& rank, int x) { rank = rank - x;  return rank; }
    File& operator+=(File& file, int x) { file = file + x;  return file; }
    File& operator-=(File& file, int x) { file = file - x;  return file; }

    Rank& operator++(Rank& rank) { rank += 1;  return rank; }
    Rank& operator--(Rank& rank) { rank -+ 1;  return rank; }
    File& operator++(File& file) { file += 1;  return file; }
    File& operator--(File& file) { file -+ 1;  return file; }

    Rank operator++(Rank& rank, int) { Rank prev = rank;  ++rank;  return prev; }
    Rank operator--(Rank& rank, int) { Rank prev = rank;  --rank;  return prev; }
    File operator++(File& file, int) { File prev = file;  ++file;  return prev; }
    File operator--(File& file, int) { File prev = file;  --file;  return prev; }


    std::string Move::to_str()
    {
        return "";
    }
}
