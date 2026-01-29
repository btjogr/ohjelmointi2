#include "rook.hh"

Rook::Rook(ChessColor col):  ChessPiece(col, ROOK, "Rook")
{

}


set<Coord> Rook::get_allowed_moves(const ChessBoard &board) const
{
    set<Coord> moves;
    auto [row, col] = get_position();



    for(int i=1;i<=8;i++){

        //suunnat
        check_move(board, {row + i, col}, moves);

        check_move(board, {row - i, col}, moves);

        check_move(board, {row, col + i}, moves);

        check_move(board, {row, col -i}, moves);

    }


    return moves;
}

//palautus vaihdettu booliksi
bool Rook::check_move(const ChessBoard &board, const Coord &dest, set<Coord> &moves) const
{
    // Add the move, if the square is in bounds, it's empty or there is an enemy piece
    if (board.coord_in_bounds(dest))
    {
        shared_ptr<ChessPiece> piece = board.get_piece_at(dest);
        if (piece == nullptr || piece->get_color() != get_color())
        {
            moves.insert(dest);
            return true;
        }
    }

    return false;
}
