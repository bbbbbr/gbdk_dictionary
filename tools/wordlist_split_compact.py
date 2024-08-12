import argparse
import re

# Takes a word list text file (one word per line)
# - Filters to min/max length and splits it into separate word list files
#   based on first letter and word length
# - Each word has the first letter stripped (to save space) and all the words are
#   concatenated into a single string, so that they can be indexed by
#   word N is at: start of string + (N * 2)


def process_word_list(file_path, min_length=0, max_length=None, output_folder='.'):
    # Read the word list from the file
    with open(file_path, 'r') as file:
        words = file.read().splitlines()
    
    # Filter words by length
    filtered_words = [word for word in words if len(word) >= min_length]
    if max_length:
        filtered_words = [word for word in filtered_words if len(word) <= max_length]
    
    # Convert to lowercase and sort
    lowercase_sorted_words = sorted([word.lower() for word in filtered_words])
    
    # Separate words by length and first letter
    groups = {}
    for word in lowercase_sorted_words:
        key = (len(word), word[0])
        if key not in groups:
            groups[key] = []
        groups[key].append(word)
    
    # Process each group
    for length, first_letter in groups.keys():
        output_string = ''.join([re.sub(f'^{first_letter}', '', word) for word in groups[(length, first_letter)]])
        
        # Write to file
        filename = f"{length}_{first_letter}_words.txt"
        output_file_path = f"{output_folder}/{filename}"
        with open(output_file_path, 'w') as outfile:
            outfile.write(output_string)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Process a word list.')
    parser.add_argument('wordlist_textfile', type=str, help='Path to the word list text file, one word per line')
    parser.add_argument('--min',             type=int, default=0, help='Minimum word length')
    parser.add_argument('--max',             type=int, help='Maximum word length')
    parser.add_argument('--output_folder',   type=str, default='.', help='Folder to save output files (must exist)')

    args = parser.parse_args()

    process_word_list(args.wordlist_textfile, args.min, args.max, args.output_folder)
