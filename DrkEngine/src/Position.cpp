
#include "Position.h"


namespace Drk::Chess
{
    Position::Position(void)
    {
        load_from_file("DrkEngine/resources/starting_position.drk");
        flags.opening = true;
    }

    void Position::load_from_file(const char* fp)
    {
        std::ifstream iFile(fp, std::ifstream::in);
        ASSERT(iFile.is_open(), "Could not open <file>.");

        // ASSERT if file is not a valid .drk

        std::string line;

        for (Rank rank = R8; rank >= R1; rank++)
        {
            std::getline(iFile, line);

            std::string pieceStr;

            for (File file = Fa; file <= Fh; file++)
            {
                pieceStr = line.substr((int)file * 3, 2);

                Ptr<Piece> piece = Piece::create((PieceEnum)pieceStr[1], { rank, file }, (Color)pieceStr[0]);
                board.board[rank][file] = piece;
            }
        }
    }

    void Position::save_to_file(const char* fp) const
    {
        std::ofstream oFile(fp, std::ofstream::out);
        ASSERT(oFile.is_open(), "Could not open <file>.");

        for (Rank rank = R8; rank >= R1; rank--) // Use iterators
        {
            for (File file = Fa; file <= Fh; file++)
            {
                Ptr<Piece> piece = board.board[rank][file];
                oFile << (char)(piece->get_color()) << piece->get_symbol();

                if (file != Fh)
                    oFile << "|";
            }
            oFile << std::endl;
        }
        oFile << (char)toPlay << "-";
        oFile << (flags.castleWhite ? "CW" : " ") << "-";
        oFile << (flags.castleBlack ? "CB" : " ");
    }
}
