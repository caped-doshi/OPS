import glob
import os
import pandas as pd

# Combine all CSV files into one
all_files = glob.glob("../data/nasdaq100/*.csv")
combined_data = pd.concat((pd.read_csv(f) for f in all_files), ignore_index=True)

# Save combined data to a single CSV file
combined_data.to_csv("../data/nasdaq100_combined_5y.csv", index=False)
print("Combined data saved to nasdaq100_combined_5y.csv")