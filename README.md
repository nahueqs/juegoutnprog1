🛡️ Juego de Tronos - TP Integrador Programación I - UTN Facultad Regional General Pacheco - 1C 2025

¿Cómo se juega?
El jugador elige una casa (Stark, Lannister, Targaryen), cada una con sus propias ventajas y habilidades activas. Deberá:

- Reclutar soldados 🪖
- Comprar comida 🍗
- Mejorar habilidades activas ✨
- Enfrentar 10 batallas ⚔️
  
Condiciones de derrota:
- Perder 4 batallas = fin del juego

Condiciones de victoria:
- Sobrevivir todas las batallas con los mejores recursos posibles.

Requisitos del Proyecto
- CodeBlocks
- Sin variables globales
- Código modular con archivos `.h` y `.cpp`
- Uso de estructuras, funciones y lógica de programación estructurada

Lógica de Batallas
- Cada ronda tiene una **probabilidad base** de victoria decreciente
- Solo pueden luchar los soldados que hayan sido **alimentados**
- Se pierden tropas según la fórmula: `5 * ronda %`
- Ganar una batalla otorga oro creciente según la ronda

