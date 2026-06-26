```ui
// Manager controls
manage_value(5)
manage_action("cast")
slot_level(1)

text("[color=#AAAAAA]HP[/color] ") int(manage_value, "", 80, true) button("Damage", 60, manage_action="damage") button("Heal", 45, manage_action="heal") button("Temp", 45, manage_action="temp_heal")

text("[color=#AAAAAA]Rest[/color] ") button("Short Rest", 90, manage_action="short_rest") button("Long Rest", 90, manage_action="long_rest")

text("[color=#AAAAAA]Spell Slot[/color] ") int(slot_level, "Level", 65, true) button("Cast", 90, manage_action="cast")
if(slot_level > 4){ slot_level = 4 }
if(slot_level < 0){ slot_level = 0 }

// Damage: temp HP absorbs first
damage_to_temp(manage_value > hp_temp ? hp_temp : manage_value)
damage_to_hp(manage_value - damage_to_temp)

if(manage_action == "damage") {
  hp_temp = hp_temp - damage_to_temp
  hp_current = hp_current - damage_to_hp
  hp_current = hp_current < 0 ? 0 : hp_current
  manage_action = "none"
}

// Heal: cannot exceed max HP
if(manage_action == "heal") {
  hp_current = hp_current + manage_value
  hp_current = hp_current > hp_max ? hp_max : hp_current
  manage_action = "none"
}

// Temp Heal: adds temporary HP
if(manage_action == "temp_heal") {
  hp_temp = hp_temp + manage_value
  manage_action = "none"
}

// Short Rest
if(manage_action == "short_rest") {
  hit_dice_spent = 0
  manage_action = "none"
}

// Long Rest
if(manage_action == "long_rest") {
  hp_current = hp_max
  hp_temp = 0

  hit_dice_spent = 0

  spell_slot_expended[0] = 0
  spell_slot_expended[1] = 0
  spell_slot_expended[2] = 0
  spell_slot_expended[3] = 0
  spell_slot_expended[4] = 0

  sorcery_points = sorcery_points_max

  manage_action = "none"
}

// Cast spell slot
if((starts_with(manage_action , "cast")) && (slot_level == 1) && (spell_slot_expended[0] < spell_slot_total[0])) {
  spell_slot_expended[0] += 1
  manage_action = "none"
}
if(manage_action == "cast" && slot_level == 2 && spell_slot_expended[1] < spell_slot_total[1]) {
  spell_slot_expended[1] += 1
  manage_action = "none"
}
if(manage_action == "cast" && slot_level == 3 && spell_slot_expended[2] < spell_slot_total[2]) {
  spell_slot_expended[2] += 1
  manage_action = "none"
}
if(manage_action == "cast" && slot_level == 4 && spell_slot_expended[3] < spell_slot_total[3]) {
  spell_slot_expended[3] += 1
  manage_action = "none"
}
if(manage_action == "cast" && slot_level == 5 && spell_slot_expended[4] < spell_slot_total[4]) {
  spell_slot_expended[4] += 1
  manage_action = "none"
}
```