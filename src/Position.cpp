
#include "Position.hpp"

#include <fstream>


namespace Drk::Chess
{
    Position::Position(void)
    {
        load_from_file("DrkEngine/resources/starting_position.drk");
        m_flags.opening = true;
    }

    std::vector<Move> Position::get_legal_moves(void) const
    {
        std::vector<Move> moves;

        for (const auto& piece : m_board)
            if (piece->get_color() == m_toPlay)
            {
                const std::vector<Move> pieceMoves = piece->get_moves();
                moves.insert(moves.end(), pieceMoves.begin(), pieceMoves.end());
            }

        
        // Add castling

        return moves;
        

        // auto it = moves.begin();
        // while (it != moves.end())
        // {
        //     auto& move = *it;
        //     bool remove = false;

        //     if (!check_legal_move(move))
        //         remove = true;

            

        //     if (remove)
        //         it = moves.erase(it);
        //     else
        //         it++;
        // }
    }

    bool Position::can_castle(void)
    {
        if (m_toPlay == Color::None)
            return false;
        else
        {
            if (((m_toPlay == Color::White) ? m_flags.castleWhite : m_flags.castleBlack) == true)
                return check_can_castle();
            else
                return false;
        }
    }

    bool Position::check_legal_move(const Move& move) const
    {
        

        // if (flags.in_check(m_toPlay))
        //     check_illegal_move_in_check()
    }

    bool Position::check_can_castle(void)
    {
        // //Check
        bool result = false;
        if (m_toPlay == Color::White)
        {

            m_flags.castleWhite = result;
            return result;
        }
        else if (m_toPlay == Color::White)
        {
            
            m_flags.castleBlack = result;
            return result;
        }
        else
            return false;
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
                m_board.set_piece(piece);
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
                Ptr<Piece> piece = m_board.get_piece(r, f);
                oFile << to_char(piece->get_color()) << piece->get_symbol();

                if (f < 7)
                    oFile << "|";
            }
            oFile << std::endl;
        }
        oFile << to_char(m_toPlay) << "-";
        oFile << (m_flags.castleWhite ? "CW" : " ") << "-";
        oFile << (m_flags.castleBlack ? "CB" : " ");
    }
}
