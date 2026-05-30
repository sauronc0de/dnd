```ui
manage_action("none") 
slot_level(1)

if(starts_with(manage_action, "cast") && slot_level == 1 && spell_slot_expended[0] < spell_slot_total[0]) {

  manage_action = "none"
}
```