import pandas as pd
import matplotlib.pyplot as plt
import os

# Cargar los datos de puntos desde data2k.csv
data_points = pd.read_csv("data/data2k.csv", header=None)

# Función para cargar y visualizar los resultados de clustering de ambos métodos
def plot_clusters_comparison(data_points, bf_assignments_file, bf_centroids_file, kd_assignments_file, kd_centroids_file, experiment_id):
    # Cargar los datos de asignaciones y centroides para BF y KD
    bf_assignments = pd.read_csv(bf_assignments_file)
    bf_centroids = pd.read_csv(bf_centroids_file, header=None)
    kd_assignments = pd.read_csv(kd_assignments_file)
    kd_centroids = pd.read_csv(kd_centroids_file, header=None)

    # Crear una figura con dos subplots, uno para BF y otro para KD
    fig, axs = plt.subplots(1, 2, figsize=(14, 6))

    # Visualización para el método de fuerza bruta (BF)
    for cluster_id in bf_assignments['cluster'].unique():
        cluster_points_ids = bf_assignments[bf_assignments['cluster'] == cluster_id]['point_id']
        cluster_points = data_points.iloc[cluster_points_ids]  # Filtrar puntos en data2k.csv
        axs[0].scatter(cluster_points[0], cluster_points[1], label=f"Cluster {cluster_id}", alpha=0.6, s=10)

    axs[0].scatter(bf_centroids[0], bf_centroids[1], c='black', marker='x', s=100, label='Centroids')
    axs[0].set_title(f"Fuerza Bruta - Experimento {experiment_id}")
    axs[0].set_xlabel("X")
    axs[0].set_ylabel("Y")

    # Visualización para el método de KD-tree
    for cluster_id in kd_assignments['cluster'].unique():
        cluster_points_ids = kd_assignments[kd_assignments['cluster'] == cluster_id]['point_id']
        cluster_points = data_points.iloc[cluster_points_ids]  # Filtrar puntos en data2k.csv
        axs[1].scatter(cluster_points[0], cluster_points[1], label=f"Cluster {cluster_id}", alpha=0.6, s=10)

    axs[1].scatter(kd_centroids[0], kd_centroids[1], c='black', marker='x', s=100, label='Centroids')
    axs[1].set_title(f"KD-tree - Experimento {experiment_id}")
    axs[1].set_xlabel("X")

    # Guardar la imagen
    plt.suptitle(f"Comparación de Clustering - Experimento {experiment_id}")
    output_file = f"images/cluster_comparison_{experiment_id}.png"
    plt.savefig(output_file)
    plt.close()
    print(f"Gráfico guardado: {output_file}")

# Ejecutar la visualización para cada conjunto de experimentos
for experiment_id in range(1, 11):
    bf_assignments_file = f"data/bf_assignments_{experiment_id}.csv"
    bf_centroids_file = f"data/bf_cluster_{experiment_id}.csv"
    kd_assignments_file = f"data/kd_assignments_{experiment_id}.csv"
    kd_centroids_file = f"data/kd_cluster_{experiment_id}.csv"
    
    # Verificar si los archivos existen antes de graficar
    if (os.path.exists(bf_assignments_file) and os.path.exists(bf_centroids_file) and
        os.path.exists(kd_assignments_file) and os.path.exists(kd_centroids_file)):
        plot_clusters_comparison(data_points, bf_assignments_file, bf_centroids_file, kd_assignments_file, kd_centroids_file, experiment_id)
    else:
        print(f"Archivos no encontrados para el experimento {experiment_id}.")
