```ui
// Hit points
text("[color=#FF5555]Hit Points[/color]")

damage_amount(-5)
heal_amount(2)

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
```