
#include "Pieces.h"


namespace Drk::Chess
{
    Ptr<Piece> Piece::create(PieceEnum piece, Square square, Color color)
    {
        switch (piece)
        {
            case PieceEnum::King   : return make_ptr<Pieces::King>   (square, color);
            case PieceEnum::Queen  : return make_ptr<Pieces::Queen>  (square, color);
            case PieceEnum::Rook   : return make_ptr<Pieces::Rook>   (square, color);
            case PieceEnum::Bishop : return make_ptr<Pieces::Bishop> (square, color);
            case PieceEnum::Knight : return make_ptr<Pieces::Knight> (square, color);
            case PieceEnum::Pawn   : return make_ptr<Pieces::Pawn>   (square, color);
            case PieceEnum::None   : 
            default                : return make_ptr<Pieces::None>   (square, color);
        }
    }


    namespace Pieces
    {
        None  ::None   (Square square, Color color) : Piece(PieceEnum::None,   square, Color::None, 0 ) {}
        King  ::King   (Square square, Color color) : Piece(PieceEnum::King,   square, color, 100) {}
        Queen ::Queen  (Square square, Color color) : Piece(PieceEnum::Queen,  square, color, 9) {}
        Rook  ::Rook   (Square square, Color color) : Piece(PieceEnum::Rook,   square, color, 5) {}
        Bishop::Bishop (Square square, Color color) : Piece(PieceEnum::Bishop, square, color, 3) {}
        Knight::Knight (Square square, Color color) : Piece(PieceEnum::Knight, square, color, 3) {}
        Pawn  ::Pawn   (Square square, Color color) : Piece(PieceEnum::Pawn,   square, color, 1) {}
    }
}
