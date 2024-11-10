import pandas as pd
import matplotlib.pyplot as plt

file_path = 'data/times_n_fixed.csv'
data = pd.read_csv(file_path, header=None, names=['k', 'n', 'kmeansbf', 'kmeanskd'])

ns1 = [1000, 1450, 1900, 2400]

def plot_for_specified_k(data, ks1):
    for k in ns1:
        subset = data[data['n'] == k]
        
        plt.figure(figsize=(10, 6))
        plt.plot(subset['k'], subset['kmeansbf'], label='kmeansbf', marker='o')
        plt.plot(subset['k'], subset['kmeanskd'], label='kmeanskd', marker='x')
        
        plt.xlabel('k (clusters)')
        plt.ylabel('Time (ms)')
        plt.title(f'K-Means Time Analysis for n = {k}')
        plt.legend()

        file_name = f'images/time_analysis_n_{k}.png'
        plt.savefig(file_name)
        plt.close()
        
        print(f"Plot saved for n={k} as {file_name}")

plot_for_specified_k(data, ns1)
