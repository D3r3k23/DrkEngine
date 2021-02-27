
#include "ChessPrimitives.hpp"


namespace Drk::Chess
{
    int to_index(Rank rank) { return static_cast<int> (rank);  }
    int to_index(File file) { return static_cast<int> (file);  }
    Rank to_rank(int index) { return static_cast<Rank>(index); }
    File to_file(int index) { return static_cast<File>(index); }

    char to_char(Rank rank) { return static_cast<char>(      to_index(rank) + to_index(Rank::R1)); }
    char to_char(File file) { return static_cast<char>(      to_index(file) + to_index(File::Fa)); }
    Rank to_rank(char ch)   { return static_cast<Rank>(static_cast<int>(ch) - to_index(Rank::R1)); }
    File to_file(char ch)   { return static_cast<File>(static_cast<int>(ch) - to_index(File::Fa)); }

    bool operator>(const Rank& lhs, const Rank& rhs) { return to_index(lhs) > to_index(rhs); }
    bool operator<(const File& lhs, const File& rhs) { return to_index(lhs) < to_index(rhs); }

    Rank operator+(const Rank& rank, int x)
    {
        int nRank = to_index(rank) + x;
        
        if (nRank < 0)
            return Rank::R1;
        else if (nRank > 7)
            return Rank::R8;
        else
            return to_rank(nRank);
    }

    File operator+(const File& file, int x)
    {
        int nFile = to_index(file) + x;
        
        if (nFile < 0)
            return File::Fa;
        else if (nFile > 7)
            return File::Fh;
        else
            return to_file(nFile);
    }

    Rank operator-(const Rank& rank, int x)
    {
        int nRank = to_index(rank) - x;
        
        if (nRank < 0)
            return Rank::R1;
        else if (nRank > 7)
            return Rank::R8;
        else
            return to_rank(nRank);
    }

    File operator-(const File& file, int x)
    {
        int nFile = to_index(file) - x;
        
        if (nFile < 0)
            return File::Fa;
        else if (nFile > 7)
            return File::Fh;
        else
            return to_file(nFile);
    }

    Rank& operator+=(Rank& rank, int x) { rank = to_rank(to_index(rank) + x);  return rank; }
    File& operator+=(File& file, int x) { file = to_file(to_index(file) + x);  return file; }
    Rank& operator-=(Rank& rank, int x) { rank = to_rank(to_index(rank) - x);  return rank; }
    File& operator-=(File& file, int x) { file = to_file(to_index(file) - x);  return file; }

    Rank& operator++(Rank& rank) { rank += 1;  return rank; }
    File& operator++(File& file) { file += 1;  return file; }
    Rank& operator--(Rank& rank) { rank -= 1;  return rank; }
    File& operator--(File& file) { file -= 1;  return file; }

    Rank operator++(Rank& rank, int) { Rank prev = ++rank;  return prev; }
    File operator++(File& file, int) { File prev = ++file;  return prev; }
    Rank operator--(Rank& rank, int) { Rank prev = --rank;  return prev; }
    File operator--(File& file, int) { File prev = --file;  return prev; }


    PieceEnum to_piece_enum(char ch) { return static_cast<PieceEnum>(ch); }
    char to_char(PieceEnum piece)    { return static_cast<char>(piece);   }

    Color to_color(char ch)   { return static_cast<Color>(ch);   }
    char to_char(Color color) { return static_cast<char>(color); }
}
