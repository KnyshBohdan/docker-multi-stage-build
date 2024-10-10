import csv
import random

def generate_data(num_rows, num_cols, filename):
    with open(filename, 'w', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        for _ in range(num_rows):
            row = [random.uniform(0, 100) for _ in range(num_cols)]
            csvwriter.writerow(row)

if __name__ == '__main__':
    num_rows = 1000
    num_cols = 10
    filename = 'data.csv'
    generate_data(num_rows, num_cols, filename)
