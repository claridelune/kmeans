import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos de tiempo
data_k_fixed = pd.read_csv("data/times_k_fixed.csv", header=None, names=["k", "n", "time_without_kdtree", "time_with_kdtree"])
data_n_fixed = pd.read_csv("data/times_n_fixed.csv", header=None, names=["k", "n", "time_without_kdtree", "time_with_kdtree"])

def plot_time_analysis_k_fixed(data):
    plt.figure(figsize=(10, 8))
    
    # Graficar cada valor de k como una serie separada
    for k_value in data['k'].unique():
        subset = data[data['k'] == k_value]
        plt.plot(subset['n'], subset['time_without_kdtree'], label=f'Brute-force, k={k_value}', linestyle='--')
        plt.plot(subset['n'], subset['time_with_kdtree'], label=f'KD-tree, k={k_value}', linestyle='-')
    
    plt.xlabel("Número de puntos (n)")
    plt.ylabel("Tiempo de ejecución (s)")
    plt.title("Tiempo de ejecución para K-means (k fijo)")
    plt.legend()
    output_file = "images/time_analysis_k_fixed.png"
    plt.savefig(output_file)
    plt.close()
    print(f"Gráfico de tiempo guardado: {output_file}")

def plot_time_analysis_n_fixed(data):
    plt.figure(figsize=(10, 8))
    
    # Graficar cada valor de n como una serie separada
    for n_value in data['n'].unique():
        subset = data[data['n'] == n_value]
        plt.plot(subset['k'], subset['time_without_kdtree'], label=f'Brute-force, n={n_value}', linestyle='--')
        plt.plot(subset['k'], subset['time_with_kdtree'], label=f'KD-tree, n={n_value}', linestyle='-')
    
    plt.xlabel("Número de clusters (k)")
    plt.ylabel("Tiempo de ejecución (s)")
    plt.title("Tiempo de ejecución para K-means (n fijo)")
    plt.legend()
    output_file = "data/time_analysis_n_fixed.png"
    plt.savefig(output_file)
    plt.close()
    print(f"Gráfico de tiempo guardado: {output_file}")

# Generar y guardar gráficos
plot_time_analysis_k_fixed(data_k_fixed)
plot_time_analysis_n_fixed(data_n_fixed)
