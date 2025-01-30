---
aliases: 
tags:
  - Entity/Player-Character
  - Multiverse/D&D
cssclasses:
  - hcl
  - table
  - t-c
  - readable
stats_list: STR, DEX, CON, INT, WIS, CHA
STR: 8
DEX: 14
CON: 14
INT: 20
WIS: 12
CHA: 10
proficiency: 4
Creator: Sergi Verdaguer
Universe: Forgotten Realms
Campaign: Curse of Strahd
Adventure_Diary: "1"
Character_name: Timmy Lannethorn
Skills:
  - Arcana
  - History
  - Investigation
  - Insight
SavingThrows:
  - INT
  - WIS
---
# Timmy Lannethorn

> (Description:: **`=this.Character_name`** és el fill més jove de Lord Tiberian Lannethorn i el germà petit de Celeste i Joran Lannethorn. Com a [[Halfling]], confia en la seva intel·ligència aguda i en el seu domini de la màgia per superar els reptes tant de la intriga cortesana com de l'estudi arcà. Sovint subestimat per la seva estatura, Tyrian ha perfeccionat el seu enginy i les seves habilitats màgiques per burlar els adversaris i desafiar les expectatives.)

--- start-multi-column: CharacterIntro  

```column-settings  
number of columns: 2  
Border: disabled
Shadow: off
Overflow: [Hidden, Hidden]
Content Overflow: [Hidden, Hidden]
Alignment: [Left, Center]
```


![Timmy](Images/Tyrion_Avatar_Little.png)


--- end-column ---

| **Attribute**  | **Value**          |
| -------------- | ------------------ |
| **Class**      | Wizard (Evocation) |
| **Level**      | 9                  |
| **Race**       | [[Halfing]]        |
| **Alignment**  | Neutral            |
| **Background** | Sage               |

--- end-multi-column


# Stats

|HP|AC|Speed|Initiative|
|:-:|:-:|:-:|:-:|
|54|15|30 ft|+2|

|Hit Dice|Proficiency Bonus|Temp HP|
|:-:|:-:|:-:|
|9d6|+4|0|

|Senses|#|
|---|---|
|**Passive Perception**|11|

---

## Abilities

### Abilities

|STR|DEX|CON|INT|WIS|CHA||
|:-:|:-:|:-:|:-:|:-:|:-:|---|
|`=this.STR`|`=this.DEX`|`=this.CON`|`=this.INT`|`=this.WIS`|`=this.CHA`|**Stats**|
|`$=((dv.current().STR - 10)/2 > -1 ? "+" : "") + (dv.current().STR - 10)/2`|`$=((dv.current().DEX - 10)/2 > -1 ? "+" : "") + (dv.current().DEX - 10)/2`|+`=(this.CON - 10)/2`|+`=(this.INT - 10)/2`|+`=(this.WIS - 10)/2`|+`=(this.CHA - 10)/2`|**Modifier**|
|-1|+2|+2|+8|+4|+0|**Saving Throw**|

### Skills

|                                                                                 #                                                                                 | Skill            | Ability |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------: | ---------------- | :-----: |
|    `$=((dv.current().DEX - 10)/2 > -1 ? "+" : "") + ((dv.current().DEX - 10)/2 + (dv.current().Skills.includes("Acrobatics") ? dv.current().Proficiency : 0))`    | Acrobatics       |   DEX   |
| `$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + ((dv.current().WIS - 10)/2 + (dv.current().Skills.includes("Animal Handling") ? dv.current().Proficiency : 0))`  | Animal Handling  |   WIS   |
|      `$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + ((dv.current().INT - 10)/2 + (dv.current().Skills.includes("Arcana") ? dv.current().proficiency : 0))`      | Arcana           |   INT   |
|    `$=((dv.current().STR - 10)/2 > -1 ? "+" : "") + ((dv.current().STR - 10)/2 + (dv.current().Skills.includes("Athletics") ? dv.current().proficiency : 0))`     | Athletics        |   STR   |
|    `$=((dv.current().CHA - 10)/2 > -1 ? "+" : "") + ((dv.current().CHA - 10)/2 + (dv.current().Skills.includes("Deception") ? dv.current().proficiency : 0))`     | Deception        |   CHA   |
|     `$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + ((dv.current().INT - 10)/2 + (dv.current().Skills.includes("History") ? dv.current().proficiency : 0))`      | History          |   INT   |
|     `$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + ((dv.current().INT - 10)/2 + (dv.current().Skills.includes("Insight") ? dv.current().proficiency : 0))`      | Insight          |   INT   |
|   `$=((dv.current().CHA - 10)/2 > -1 ? "+" : "") + ((dv.current().CHA - 10)/2 + (dv.current().Skills.includes("Intimidation") ? dv.current().proficiency : 0))`   | Intimidation     |   CHA   |
|  `$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + ((dv.current().INT - 10)/2 + (dv.current().Skills.includes("Investigation") ? dv.current().proficiency : 0))`   | Investigation    |   INT   |
|     `$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + ((dv.current().WIS - 10)/2 + (dv.current().Skills.includes("Medicine") ? dv.current().Proficiency : 0))`     | Medicine         |   WIS   |
|      `$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + ((dv.current().WIS - 10)/2 + (dv.current().Skills.includes("Nature") ? dv.current().Proficiency : 0))`      | Nature           |   WIS   |
|    `$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + ((dv.current().WIS - 10)/2 + (dv.current().Skills.includes("Perception") ? dv.current().Proficiency : 0))`    | Perception       |   WIS   |
|    `$=((dv.current().CHA - 10)/2 > -1 ? "+" : "") + ((dv.current().CHA - 10)/2 + (dv.current().Skills.includes("Persuasion") ? dv.current().proficiency : 0))`    | Persuasion       |   CHA   |
|     `$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + ((dv.current().INT - 10)/2 + (dv.current().Skills.includes("Religion") ? dv.current().proficiency : 0))`     | Religion         |   INT   |
| `$=((dv.current().DEX - 10)/2 > -1 ? "+" : "") + ((dv.current().DEX - 10)/2 + (dv.current().Skills.includes("Sleight of hands") ? dv.current().Proficiency : 0))` | Sleight of hands |   DEX   |
|     `$=((dv.current().DEX - 10)/2 > -1 ? "+" : "") + ((dv.current().DEX - 10)/2 + (dv.current().Skills.includes("Stealth") ? dv.current().Proficiency : 0))`      | Stealth          |   DEX   |
|     `$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + ((dv.current().WIS - 10)/2 + (dv.current().Skills.includes("Survival") ? dv.current().Proficiency : 0))`     | Survival         |   WIS   |


# Traits

- **Arcane Recovery**: Recover up to 5 spell levels during a short rest.
- 
- **Sculpt Spells**: Allies auto-succeed on saving throws for Evocation spells.
- **Potent Cantrip**: Enemies take half damage even if they save.
- **War Caster**: Advantage on CON saves to maintain concentration; can cast spells as opportunity attacks.
- **Elemental Adept (Fire)**: Spells ignore fire resistance; 1s on fire damage rolls become 2s.

## Proficiencies

- Saving Throws: Intelligence (+8), Wisdom (+`=this.pro`)
- Skills: Arcana, History, Investigation, Insight
- Weapons: Quarterstaff (rarely used)
- Tools: None (focus on spellcasting)

## Languages

- Common
- Draconic
- Elvish

# Actions

```meta-bind-button
label: Add actions
icon: ""
style: default
class: ""
cssStyle: ""
backgroundImage: ""
tooltip: ""
id: ""
hidden: false
actions: []

```

- **Attack**: Quarterstaff (only if necessary, +1 to hit, 1d6 bludgeoning damage)
- **Cast Spells**: Offensive and defensive utility (see Spell List)

## Spells

| Level | Spell Slots |                 Prepared Spells                  |
| :---: | :---------: | :----------------------------------------------: |
|   1   |      4      | Shield, Mage Armor, Magic Missile, Detect Magic  |
|   2   |      3      | Misty Step, Mirror Image, Scorching Ray, Shatter |
|   3   |      3      |       Fireball, Counterspell, Dispel Magic       |
|   4   |      3      |         Greater Invisibility, Polymorph          |
|   5   |      1      |           Wall of Force, Cone of Cold            |

Cantrips: Fire Bolt, Ray of Frost, Minor Illusion, Prestidigitation, Mage Hand

# Equipment

|CP|SP|EP|GP|PP|
|:-:|:-:|:-:|:-:|:-:|
|0|0|0|100|5|

- **Weapons**: [[Dagger]] and [[Quarterstaff]]
- **Armor**: [[Mage Armor]]
- **Magic Items**:
    - [[Cloak of Protection]]
    - [[Staff of Fire]] 
    - [[Ring of Spell Storing]]

## Loot and resources

- Rope:

# Personality

- Respecta pels marginats
- Pacifista
- **Trastorn evasiu** degut al seu passat. Culpat per la mort de la seva mare i el rebuig que rep pels demés. Sovint detonant en alchol i sexe

# Strategy

- Control the battlefield with **Wall of Force** and **Counterspell**.
- Deal high damage with **Fireball** and **Cone of Cold**, sculpting spells to protect allies.
- Use concentration spells like **Polymorph** and **Greater Invisibility** to turn the tide of battle.
- Maintain mobility with **Misty Step** to avoid melee threats.

# Background

**Tyrian Lannethorn**, fill més jove de Lord Tiberian Lannethorn, va néixer en una família poderosa i orgullosa, coneguda per les seves terres vastes i les seves influències polítiques. El seu pare, un home alt i imponent, i els seus germans, Celeste i Joran, sempre l’han considerat un fracàs. A diferència dels seus germans, que van heretar la força i l’habilitat per les arts de la guerra, Tyrian era petit, i la seva estatura d’un mighome feia que tothom el veiés com a feble i inútil. Però el que la seva família no va entendre mai va ser que el petit Tyrian era, de fet, el més perillós de tots.

En un món ple de guerres, traïcions i màgia, la seva veritable força no era la força física, sinó la seva ment afilada i la seva connexió amb les arts arcàniques. Des de ben jove, Tyrian va descobrir que la màgia era el seu camí per demostrar el seu valor. Va estudiar sota els millors mestres d'arcans, subratllant les tècniques més complexes de la màgia de control i il·lusió, aprofitant la seva aguda ment i capacitat de lectura d’emocions i situacions.

Malgrat la seva brillantor, les portes de la cort es van tancar per a ell. La seva família, i especialment el seu germà Joran, que desitjava la glòria en el camp de batalla, considerava que un mag tan petit no tenia cap lloc al seu costat. Però Tyrian va aprendre a ser més astut que qualsevol cavaller. Va començar a manipular les subtilitats polítiques de la cort amb un somriure subtil, utilitzant la seva intel·ligència per convèncer als altres, per manipular els esdeveniments des de les ombres.

El seu gran moment va arribar quan el regne es va veure amenaçat per un nou enemic: un governant estranger amb una força militar formidable i un poder màgic desconegut. La seva família, desconcertada i aterrida, va intentar una aliança amb el rei rival. Però Tyrian, amb les seves habilitats màgiques, va veure una oportunitat de redimir-se i salvar el seu nom. Va utilitzar les seves habilitats d'il·lusió i encantament per enganyar l'enemic, convencent-lo que els seus exèrcits eren més nombrosos del que realment eren i que l'aliança amb el regne era una trampa.

Quan el conflicte va arribar a l’extrem, va ser Tyrian qui, amb un conjur astut, va envair els somnis del líder enemic, fent-li veure una visió aterradora d'una traïció interna. El líder va caure en el parany, i amb la seva retirada, el regne va ser salvat. Aquest acte va catapultar Tyrian al reconeixement i la seva família, que abans el menyspreava, va veure finalment el veritable valor que aportava. Però Tyrian sabia que no era la glòria que volia; el que realment desitjava era la llibertat per viure segons les seves pròpies regles.

Ara, Tyrian viatja pel món, buscant més coneixements arcans, utilitzant la seva màgia per defensar els innocents i mantenint sempre un ull sobre les intrigues que es desenvolupen a les corts i els regnes. La seva astúcia i les seves habilitats màgiques el converteixen en un aliat valuós per aquells que el coneixen, però també en un enemic temible per aquells que s’atreveixen a subestimar-lo.

# Current Match


## Current Stats
- **HP**: [Curresnt HP] / [Max HP]
- **Temporary Hit Points**: [Temp HP]
- **Hit Dice**: [Hit Dice Remaining]
- **AC**: [Armor s]
- **Initiative**: [Initiative Modifier]

## Spell Slots
### Level 1
- [x] **Slot 1 Available**
- [x] **Slot 2 Available**
- [x] **Slot 3 Available**
### Level 2
- [ ] **Slot 1 Available**
- [x] **Slot 2 Available**
### Level 3
- [ ] **Slot 1 Available**
### Level 4
- [x] **Slot 1 Available**
### Level 5
- [ ] **Slot 1 Available**


## Conditions
- [ ] Exhaust 
- [ ] **Poisoned**
- [ ] **Stunned**
- [ ] **Blinded**
- [ ] **Paralyzed**
- [ ] **Other**: [Other Conditions]

## Spellbook (Current Available Spells)
### Level 1

- [ ] [[Mage Armor]]
- [ ] [[Magic Missile]]
- [ ] [[Detect Magic]]

### Level 2
- [ ] [[Misty Step]]
- [ ] [[Mirror Image]]
- [ ] [[Scorching Ray]]
- [ ] [[Shatter]]

### Level 3
- [ ] [[Fireball]]
- [ ] [[Counterspell]]
- [ ] [[Dispel Magic]]

### Level 4
- [ ] [[Greater Invisibility]]
- [ ] [[Polymorph]]

### Level 5
- [ ] [[Wall of Force]]
- [ ] [[Cone of Cold]]

## Notes
- [Any additional details such as injuries, effects from previous turns, or environment-specific notes]
