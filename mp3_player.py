import pygame
import tkinter as tk
from tkinter import filedialog

def play_music():
    """Plays the selected MP3 file."""
    global paused  # Use global keyword to modify the global variable
    filename = filedialog.askopenfilename(initialdir="/", title="Select a File", 
                                          filetypes=(("MP3 files", "*.mp3"), ("all files", "*.*")))
    if filename:
        try:
            pygame.mixer.music.load(filename)
            pygame.mixer.music.play()
            play_button.config(text="Pause")
            paused = False
        except pygame.error as e:
            print(f"Error playing file: {e}")

def pause_music():
    """Pauses or unpauses the music."""
    global paused
    if paused:
        pygame.mixer.music.unpause()
        play_button.config(text="Pause")
    else:
        pygame.mixer.music.pause()
        play_button.config(text="Resume")
    paused = not paused

def stop_music():
    """Stops the music."""
    pygame.mixer.music.stop()
    play_button.config(text="Play")

# Initialize pygame mixer
pygame.mixer.init()

# Create main window
window = tk.Tk()
window.title("MP3 Player")

# Create buttons
play_button = tk.Button(window, text="Play", command=play_music)
play_button.pack()

pause_button = tk.Button(window, text="Pause/Resume", command=pause_music)
pause_button.pack()

stop_button = tk.Button(window, text="Stop", command=stop_music)
stop_button.pack()

# Initialize paused state
paused = False

# Run the main loop
window.mainloop()
