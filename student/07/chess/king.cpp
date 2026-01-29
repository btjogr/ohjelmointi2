#include "king.hh"

King::King(ChessColor col):  ChessPiece(col, KING, "King")
{

}



set<Coord> King::get_allowed_moves(const ChessBoard &board) const
{


    set<Coord> moves;
    auto [row, col] = get_position();


    // alas
    check_move(board, {row + 1, col}, moves);

    // alas oikea
    check_move(board, {row + 1, col + 1}, moves);

    // oikea
    check_move(board, {row, col + 1}, moves);

    // ylös oikea
    check_move(board, {row - 1, col + 1}, moves);
    // ylös
    check_move(board, {row - 1, col}, moves);

    // ylös vasen
    check_move(board, {row - 1, col - 1}, moves);
    // vasen
    check_move(board, {row, col - 1}, moves);

    // alas vasen
    check_move(board, {row + 1, col - 1}, moves);


    return moves;

}


//täysin sama mikä oli knightissa valmiina
void King::check_move(const ChessBoard &board, const Coord &dest, set<Coord> &moves) const
{
    // Add the move, if the square is in bounds, it's empty or there is an enemy piece
    if (board.coord_in_bounds(dest))
    {
        shared_ptr<ChessPiece> piece = board.get_piece_at(dest);
        if (piece == nullptr || piece->get_color() != get_color())
        {
            moves.insert(dest);
        }
    }
}


