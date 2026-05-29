```ui
// Hit points
text("[color=#FF5555]Hit Points[/color]")

damage_amount(2)
heal_amount(2)

text("Current HP") text(hp_current)
text("Temp HP") text(hp_temp)
text("Maximum HP") text(hp_max)

int(damage_amount, "Damage", 90, true)
button("Apply Damage", 120, hp_current=hp_current-damage_amount)

int(heal_amount, "Heal", 90, true)
button("Apply Heal", 120, hp_current=hp_current+heal_amount)

button("Full Heal", 100, hp_current=hp_max)
button("Down", 80, hp_current=0)

if(hp_current > hp_max) {
  hp_current = hp_max
}
if(hp_current < 0) {
  hp_current = 0
}

text("")

// Hit dice
text("[color=#AAAAFF]Hit Dice[/color]")

text("Spent") text(hit_dice_spent)
text("Maximum") text(hit_dice_max)

text("")

// Combat info
text("[color=#55CCFF]Combat[/color]")
```
```ui-mermaid
xychart-beta
  title "HP Bar"
  x-axis [HP]
  y-axis 0 --> ${hp_max}
  line [${hp_max}]
  bar [${hp_current + hp_temp}]
```