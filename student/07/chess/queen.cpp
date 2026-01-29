#include "queen.hh"

Queen::Queen(ChessColor col):  ChessPiece(col, QUEEN, "Queen")
{

}


set<Coord> Queen::get_allowed_moves(const ChessBoard &board) const
{

    set<Coord> moves;
    auto [row, col] = get_position();

    //pysty ja vaaka liike
    for(int i=1;i<=8;i++){

        //suunnat
        check_move(board, {row + i, col}, moves);

        check_move(board, {row - i, col}, moves);

        check_move(board, {row, col + i}, moves);

        check_move(board, {row, col -i}, moves);

    }


    //vino liike
    for(int i=1;i<=8;i++){

        //suunnat
        if(check_move(board, {row + i, col + i}, moves) && check_move(board, {row - i, col + i}, moves)
            && check_move(board, {row + i, col - i}, moves)
            &&  check_move(board, {row - i, col -i}, moves)){


            break; //jos ei pääsyä ei pyöritä turhaan

        }

    }



    return moves;











}
//täysin sama mikä oli knightissa valmiina
bool Queen::check_move(const ChessBoard &board, const Coord &dest, set<Coord> &moves) const
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
