
/*/////////////////////////////////////////////////////////
 * Basic structure for a chess board. Contains a C-array
 * of pieces. Implements non-const and const Iterators.
/*/////////////////////////////////////////////////////////

#ifndef BOARD_HPP
#define BOARD_HPP


#include "Core.hpp"
#include "ChessPrimitives.hpp"
#include "Piece.hpp"


namespace Drk::Chess
{
    class Board
    {
    public:
        class Iterator;
        class Iterator_const;

        Board(void);
        ~Board(void);

        const Piece& get_piece(int rank, int file)   const { return piece(rank, file); }
        const Piece& get_piece(Rank rank, File file) const { return piece(rank, file); }
        const Piece& get_piece(Square square)        const { return piece(square); }

        void set_piece(const Piece& newPiece);
        void set_piece(PieceEnum piece, Square square, Color color);

        void move_piece(int rank, int file);
        void move_piece(Iterator it);


        bool square_occupied(Square square) const
            { return get_piece(square).get_piece_enum() != PieceEnum::None; }


        Iterator begin(void);
        Iterator end(void);

        Iterator_const begin(void) const;
        Iterator_const end(void) const;
        

        friend class CommandLineTools;

    private:
        Piece& piece(int rank,  int file)  { return *m_board[rank][file]; }
        Piece& piece(Rank rank, File file) { return piece(to_index(rank), to_index(file)); }
        Piece& piece(Square square)        { return piece(square.rank, square.file); }

        const Piece& piece(int rank,  int file)  const { return *m_board[rank][file]; }
        const Piece& piece(Rank rank, File file) const { return piece(to_index(rank), to_index(file)); }
        const Piece& piece(Square square)        const { return piece(square.rank, square.file); }

    private:
        Ptr<Piece> m_board[8][8];

    }; // class Board


    class Board::Iterator
    {
    public:
        Iterator(Board& board, int rank, int file)
            : m_board(board), m_rank(rank), m_file(file)
        { }

        Iterator& operator++(void);
        Iterator  operator++(int);

        Piece& operator*(void) const
            { return m_board.piece(m_rank, m_file); }
        
        Piece* operator->(void) const
            { return &(m_board.piece(m_rank, m_file)); }

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
        Iterator_const  operator++(int);

        const Piece& operator*(void) const
            { return m_board.piece(m_rank, m_file); }
        
        const Piece* operator->(void) const
            { return &(m_board.piece(m_rank, m_file)); }

        bool operator!=(const Iterator_const& other) const
            { return (m_rank != other.m_rank) && (m_file != other.m_file); }

    private:
        const Board& m_board;
        int m_rank;
        int m_file;
    };
}


#endif // BOARD_HPP
