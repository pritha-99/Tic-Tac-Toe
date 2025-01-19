import tkinter as tk
import random

# Global variables
turn = 'X'  # Player 1 starts
board = [' ' for _ in range(9)]  # 3x3 board initialized to empty spaces

# Function to check for a winner
def check_win():
    winning_combinations = [(0, 1, 2), (3, 4, 5), (6, 7, 8),  # Rows
                            (0, 3, 6), (1, 4, 7), (2, 5, 8),  # Columns
                            (0, 4, 8), (2, 4, 6)]  # Diagonals
    for a, b, c in winning_combinations:
        if board[a] == board[b] == board[c] != ' ':
            return board[a]  # Return the winner symbol ('X' or 'O')
    return None

# Function to check if the game is a draw
def check_draw():
    return ' ' not in board

# Function to update the board in the GUI
def update_board(buttons):
    global turn
    for i in range(9):
        if board[i] == 'X' or board[i] == 'O':
            buttons[i].config(text=board[i], state='disabled')

# Function to handle a player's turn
def player_turn(i, buttons):
    global turn
    if board[i] == ' ':
        board[i] = turn
        update_board(buttons)
        if check_win():
            result_label.config(text=f"Player {turn} wins!")
            for button in buttons:
                button.config(state='disabled')
        elif check_draw():
            result_label.config(text="It's a draw!")
        else:
            turn = 'O' if turn == 'X' else 'X'

# Function for the system's turn (AI)
def system_turn(buttons):
    global turn
    available_moves = [i for i in range(9) if board[i] == ' ']
    if available_moves:
        move = random.choice(available_moves)
        board[move] = turn
        update_board(buttons)
        if check_win():
            result_label.config(text=f"Player {turn} wins!")
            for button in buttons:
                button.config(state='disabled')
        elif check_draw():
            result_label.config(text="It's a draw!")
        else:
            turn = 'X' if turn == 'O' else 'O'

# Function to handle a game reset
def reset_game(buttons):
    global turn, board
    board = [' ' for _ in range(9)]
    turn = 'X'
    result_label.config(text="Player X's turn")
    update_board(buttons)
    for button in buttons:
        button.config(state='normal')

# Main GUI setup
root = tk.Tk()
root.title("Tic-Tac-Toe")

buttons = [tk.Button(root, text=' ', font=('normal', 20), width=10, height=3,
                     command=lambda i=i: player_turn(i, buttons)) for i in range(9)]

# Grid Layout
for i in range(3):
    for j in range(3):
        buttons[i * 3 + j].grid(row=i, column=j)

# Result Label
result_label = tk.Label(root, text="Player X's turn", font=('normal', 14))
result_label.grid(row=3, column=0, columnspan=3)

# Reset Button
reset_button = tk.Button(root, text="Reset", font=('normal', 14), width=20, command=lambda: reset_game(buttons))
reset_button.grid(row=4, column=0, columnspan=3)

root.mainloop()
