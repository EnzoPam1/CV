#!/usr/bin/env bash
set -euo pipefail          # arrêt sur erreur / variables non-déclarées

SCENE_DIR="scenes"         # dossier où se trouvent les .cfg
RAYTRACER="./raytracer"    # exécutable
OUT_DIR="screenshots"      # où stocker les .ppm (change si besoin)

mkdir -p "$OUT_DIR"        # crée le dossier de sortie s'il n’existe pas

shopt -s nullglob          # évite la boucle si aucun .cfg

for scene in "$SCENE_DIR"/*.cfg; do
    name=$(basename "$scene" .cfg)        # ex : basic_spheres
    out="$OUT_DIR/${name}.ppm"

    echo "→ $scene  ->  $out"
    "$RAYTRACER" "$scene" > "$out"
done
