import pandas as pd
import matplotlib.pyplot as plt

file_path = 'data/times_k_fixed.csv'
data = pd.read_csv(file_path, header=None, names=['k', 'n', 'kmeansbf', 'kmeanskd'])

ks1 = [5, 15, 25, 50, 75]

def plot_for_specified_k(data, ks1):
    for k in ks1:
        subset = data[data['k'] == k]
        
        plt.figure(figsize=(10, 6))
        plt.plot(subset['n'], subset['kmeansbf'], label='kmeansbf', marker='o')
        plt.plot(subset['n'], subset['kmeanskd'], label='kmeanskd', marker='x')
        
        plt.xlabel('n (data points)')
        plt.ylabel('Time (ms)')
        plt.title(f'K-Means Time Analysis for k = {k}')
        plt.legend()
        
        file_name = f'images/time_analysis_k_{k}.png'
        plt.savefig(file_name)
        plt.close()
        
        print(f"Plot saved for k={k} as {file_name}")

plot_for_specified_k(data, ks1)
