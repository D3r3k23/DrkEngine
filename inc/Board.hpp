
#ifndef BOARD_HPP
#define BOARD_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"
#include "Pieces.hpp"


namespace Drk::Chess
{
    class Board
    {
    public:
        Board(void);

        const Ptr<Piece>& get_piece(int rank, int file) const
            { return piece(rank, file); }

        const Ptr<Piece>& get_piece(Rank rank, File file) const
            { return get_piece(to_index(rank), to_index(file)); }

        const Ptr<Piece>& get_piece(Square square) const
            { return get_piece(square.rank, square.file); }


        void set_piece(const Ptr<Piece>& newPiece);
        void set_piece(PieceEnum piece, Square square, Color color);

        void move_piece(Ptr<Piece> piece);

        bool square_occupied(Square square) const
            { return get_piece(square)->get_piece_enum() != PieceEnum::None; }


        class Iterator;
        class Iterator_const;

        Iterator begin(void);
        Iterator end(void);

        Iterator_const begin(void) const;
        Iterator_const end(void)   const;

    private:
        Ptr<Piece>& piece(int rank, int file)
            { return m_board[rank][file]; }

        const Ptr<Piece>& piece(int rank, int file) const
            { return m_board[rank][file]; }

    private:
        Ptr<Piece> m_board[8][8];
    };

    class Board::Iterator
    {
    public:
        Iterator(Board& board, int rank, int file)
            : m_board(board), m_rank(rank), m_file(file)
        { }

        Iterator& operator++(void);

        const Ptr<Piece>& operator*(void) const
            { return m_board.piece(m_rank, m_file); }

        bool operator!=(const Iterator& other) const
            { return (m_rank != other.m_rank) && (m_file != other.m_file); }

    private:
        Board& m_board;
        int m_rank;
        int m_file;
    };

    class Board::Iterator_const
    {
    public:
        Iterator_const(const Board& board, int rank, int file)
            : m_board(board), m_rank(rank), m_file(file)
        { }

        Iterator_const& operator++(void);

        const Ptr<Piece>& operator*(void) const
            { return m_board.piece(m_rank, m_file); }

        bool operator!=(const Iterator_const& other) const
            { return (m_rank != other.m_rank) && (m_file != other.m_file); }

    private:
        const Board& m_board;
        int m_rank;
        int m_file;
    };
}


#endif // BOARD_HPP
