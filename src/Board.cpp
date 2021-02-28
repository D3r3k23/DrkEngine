
#include "Board.hpp"


namespace Drk::Chess
{
    Board::Board(void)
    {
        for (int r = 0; r < 8; r++)
            for (int f = 0; f < 8; f++)
                set_piece(Piece::create(PieceEnum::None, { r, f }));
    }

    void Board::set_piece(const Ptr<Piece>& newPiece)
    {
        int rank = to_index(newPiece->get_square().rank);
        int file = to_index(newPiece->get_square().file);
        m_board[rank][file] = newPiece;
    }

    void Board::set_piece(PieceEnum piece, Square square, Color color)
    {
        auto newPiece = Piece::create(piece, square, color);
        set_piece(newPiece);
    }


    Board::Iterator Board::begin(void) { return Iterator(*this, 0, 0); }
    Board::Iterator Board::end(void)   { return Iterator(*this, 7, 7); }

    Board::Iterator_const Board::begin(void) const { return Iterator_const(*this, 0, 0); }
    Board::Iterator_const Board::end(void)   const { return Iterator_const(*this, 7, 7); }

    Board::Iterator& Board::Iterator::operator++(void)
    {
        if (m_file == 7) 
        {
            if (m_rank < 7)
            {
                m_file = 0;
                m_rank++;
            }
        }
        else
            m_file++;

        return *this;
    }

    Board::Iterator_const& Board::Iterator_const::operator++(void)
    {
        if (m_file == 7) 
        {
            if (m_rank < 7)
            {
                m_file = 0;
                m_rank++;
            }
        }
        else
            m_file++;

        return *this;
    }
}
