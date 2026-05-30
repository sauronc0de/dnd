```ui-mermaid
xychart-beta
  title "Spell Slots"

  x-axis [Lv1, Lv2, Lv3, Lv4, Lv5]
  y-axis 0 --> 4

  line [${spell_slot_remaining[0]}, ${spell_slot_remaining[1]}, ${spell_slot_remaining[2]}, ${spell_slot_remaining[3]}, ${spell_slot_remaining[4]}]
  bar [${spell_slot_total[0]}, ${spell_slot_total[1]}, ${spell_slot_total[2]}, ${spell_slot_total[3]}, ${spell_slot_total[4]}]
```