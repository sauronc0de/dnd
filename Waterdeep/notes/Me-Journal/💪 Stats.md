```ui
text("**Initiative:**") text(initiative) text(" **Speed:**") text(speed) text("**Size:**") text(size) text("**PP:**") text(passive_perception)
// Sorcery & Hit dice 
text("[color=#D4AF37]💫 Sorcery[/color] ") text(sorcery_points + "/" + sorcery_points_max) button("Spend", 50, sorcery_points = sorcery_points > 0 ? sorcery_points-1: sorcery_points) 
text("[color=#AAAAFF]🎲 Hit Dice(1d6): [/color]") text(hit_dice_max-hit_dice_spent) text("/") text(hit_dice_max) button("Spend", 50, hit_dice_spent = hit_dice_spent == hit_dice_max ? hit_dice_spent : hit_dice_spent + 1)
languages(["Common", "Gnomish", "Draconic"])
text("[color=#66AAFF]🌐 Languages[/color]")
multicheck(languages, "", 245, ["Common","Dwarvish","Elvish","Giant","Gnomish","Goblin","Halfling","Orc","Abyssal","Celestial","Deep Speech","Draconic","Infernal","Primordial","Sylvan","Undercommon","Thieves' Cant","Druidic"])
```
```ui
if(save_prof_intelligence) { text("[color=#88FFAA]Intelligence:[/color]") text(intelligence_mod) text("/") text(save_intelligence) }
if(!save_prof_intelligence) { text("[color=#88FFAA]Intelligence:[/color]") text(intelligence_mod) }

if(arcana_prof) {
  text("🔸 Arcana: ") text(arcana)
}
if(!arcana_prof) {
  text("🔹 Arcana: ") text(arcana)
}

if(history_prof) {
  text("🔸 History: ") text(history)
}
if(!history_prof) {
  text("🔹 History: ") text(history)
}

if(investigation_prof) {
  text("🔸 Investigation: ") text(investigation)
}
if(!investigation_prof) {
  text("🔹 Investigation: ") text(investigation)
}

if(nature_prof) {
  text("🔸 Nature: ") text(nature)
}
if(!nature_prof) {
  text("🔹 Nature: ") text(nature)
}

if(religion_prof) {
  text("🔸 Religion: ") text(religion)
}
if(!religion_prof) {
  text("🔹 Religion: ") text(religion)
}

if(save_prof_wisdom) { text("[color=#88FFAA]Wisdom:[/color]") text(wisdom_mod) text("/") text(save_wisdom) }
if(!save_prof_wisdom) { text("[color=#88FFAA]Wisdom:[/color]") text(wisdom_mod) }

if(animal_handling_prof) {
  text("🔸 Animal Handling: ") text(animal_handling)
}
if(!animal_handling_prof) {
  text("🔹 Animal Handling: ") text(animal_handling)
}

if(insight_prof) {
  text("🔸 Insight: ") text(insight)
}
if(!insight_prof) {
  text("🔹 Insight: ") text(insight)
}

if(medicine_prof) {
  text("🔸 Medicine: ") text(medicine)
}
if(!medicine_prof) {
  text("🔹 Medicine: ") text(medicine)
}

if(perception_prof) {
  text("🔸 Perception: ") text(perception)
}
if(!perception_prof) {
  text("🔹 Perception: ") text(perception)
}

if(survival_prof) {
  text("🔸 Survival: ") text(survival)
}
if(!survival_prof) {
  text("🔹 Survival: ") text(survival)
}

if(save_prof_dexterity) { text("[color=#FFCC88]Dexterity:[/color]") text(dexterity_mod) text("/") text(save_dexterity) }
if(!save_prof_dexterity) { text("[color=#FFCC88]Dexterity:[/color]") text(dexterity_mod) }

if(acrobatics_prof) {
  text("🔸 Acrobatics: ") text(acrobatics)
}
if(!acrobatics_prof) {
  text("🔹 Acrobatics: ") text(acrobatics)
}

if(sleight_of_hand_prof) {
  text("🔸 Sleight of Hand: ") text(sleight_of_hand)
}
if(!sleight_of_hand_prof) {
  text("🔹 Sleight of Hand: ") text(sleight_of_hand)
}

if(stealth_prof) {
  text("🔸 Stealth: ") text(stealth)
}
if(!stealth_prof) {
  text("🔹 Stealth: ") text(stealth)
}

if(save_prof_strength) { text("[color=#FF8888]Strength:[/color]") text(strength_mod) text("/") text(save_strength) }
if(!save_prof_strength) { text("[color=#FF8888]Strength:[/color]") text(strength_mod) }

if(athletics_prof) {
  text("🔸 Athletics: ") text(athletics)
}
if(!athletics_prof) {
  text("🔹 Athletics: ") text(athletics)
}

if(save_prof_charisma) { text("[color=#DDAAFF]Charisma:[/color]") text(charisma_mod) text("/") text(save_charisma) }
if(!save_prof_charisma) { text("[color=#DDAAFF]Charisma:[/color]") text(charisma_mod) }

if(deception_prof) {
  text("🔸 Deception: ") text(deception)
}
if(!deception_prof) {
  text("🔹 Deception: ") text(deception)
}

if(intimidation_prof) {
  text("🔸 Intimidation: ") text(intimidation)
}
if(!intimidation_prof) {
  text("🔹 Intimidation: ") text(intimidation)
}

if(performance_prof) {
  text("🔸 Performance: ") text(performance)
}
if(!performance_prof) {
  text("🔹 Performance: ") text(performance)
}

if(persuasion_prof) {
  text("🔸 Persuasion: ") text(persuasion)
}
if(!persuasion_prof) {
  text("🔹 Persuasion: ") text(persuasion)
}

if(save_prof_constitution) { text("[color=#DDAAFF]Constitution:[/color]") text(constitution_mod) text("/") text(save_constitution) }
if(!save_prof_constitution) { text("[color=#DDAAFF]Constitution:[/color]") text(constitution_mod) }
```
