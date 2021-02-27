
#include "Position.hpp"


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
        DRK_ASSERT(iFile.is_open(), "Could not open <file>.");

        // ASSERT if file is not a valid .drk

        std::string line;

        for (int r = 7; r >= 0; r++)
        {
            std::getline(iFile, line);

            std::string pieceStr;

            for (int f = 0; f <= 7; f++)
            {
                pieceStr = line.substr(3 * f, 2);

                Ptr<Piece> piece = Piece::create(to_piece_enum(pieceStr[1]), { r, f }, to_color(pieceStr[0]));
                board.set_piece(piece);
            }
        }
    }

    void Position::save_to_file(const char* fp) const
    {
        std::ofstream oFile(fp, std::ofstream::out);
        DRK_ASSERT(oFile.is_open(), "Could not open <file>.");

        for (int r = 7; r >= 0; r--)
        {
            for (int f = 0; f <= 7; f++)
            {
                Ptr<Piece> piece = board.get_piece(r, f);
                oFile << to_char(piece->get_color()) << piece->get_symbol();

                if (f < 7)
                    oFile << "|";
            }
            oFile << std::endl;
        }
        oFile << to_char(toPlay) << "-";
        oFile << (flags.castleWhite ? "CW" : " ") << "-";
        oFile << (flags.castleBlack ? "CB" : " ");
    }
}
