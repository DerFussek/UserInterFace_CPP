# TODO

## 0) hierarchy
Application > StateStack > UI (Widget-Tree) > Theme / UIContext > GFX (Renderer / View)
## 1) core/Application
Implementieren:
- Erstellt `sf::RenderWindow`
- Mainloop: pollEvent —> update —> render
- Ruft StateStack auf

Ergebnis: Grundgerüst des Programms steht.

---

## 2) state/State + StateStack
Implementieren:
- `State`: abstrakt mit  
  - handleEvent(const sf::Event&)  
  - update(float dt)  
  - render(sf::RenderTarget&)
- `StateStack`: push/pop, delegiert an aktiven State

Ergebnis: Programmstruktur mit Screens (Menü, Spiel, etc.).

---

## 3) ui/Widget
Implementieren:
- Basisklasse mit Position und Größe
- virtual:
  - handleEvent
  - update
  - draw
- Keine Logik, nur Interface

Ergebnis: Basis für alle UI-Elemente.

---

## 4) ui/Container
Implementieren:
- `vector<unique_ptr<Widget>> children`
- handleEvent verteilt Events an Children
- draw iteriert über Children

Ergebnis: UI-Baum existiert.

---

## 5) ui/Panel
Implementieren:
- Container + Hintergrundrechteck (sf::RectangleShape)

Ergebnis: Erstes sichtbares UI-Element.

---

## 6) ui/widgets/Label
Implementieren:
- `sf::Text`
- setText, draw

Ergebnis: Textanzeige funktioniert.

---

## 7) ui/widgets/Button
Implementieren:
- Panel + Label
- Mouse-Erkennung
- onClick Callback

Ergebnis: Klickbares UI-Element.

---

## 8) ui/layout/VBoxLayout
Implementieren:
- Ordnet Children vertikal
- padding, spacing

Ergebnis: Automatisches Layout.

---

## 9) state/MainMenuState
Implementieren:
- Baut UI: VBox —> Buttons
- Verbindet Callbacks

Ergebnis: Erstes funktionierendes Menü.

---

## 10) gfx/ViewManager
Implementieren:
- Trennung GameView / UIView
- Handhabt Resize

Ergebnis: Saubere Skalierung.

---

## Danach erweitern
- TextBox
- Slider
- Theme-System
- AssetCache
- Animationen
