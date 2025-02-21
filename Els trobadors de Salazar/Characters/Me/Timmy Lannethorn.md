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
CHA: 12
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
currentHp: 33
Level: 9
MageArmor: true
TemporaryHp: 0
NumHitDice: 9
Hp: 54
---
# Timmy Lannethorn

> (Description:: **`=this.Character_name`** és el fill més jove de Lord Tiberian Lannethorn i el germà petit de Celeste i Joran Lannethorn. Com a [[Gnome]], confia en la seva intel·ligència aguda i en el seu domini de la màgia per superar els reptes tant de la intriga cortesana com de l'estudi arcà. Sovint subestimat per la seva estatura, Timmy ha perfeccionat el seu enginy i les seves habilitats màgiques per burlar els adversaris i desafiar les expectatives.)

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

| **Attribute**  | **Value**                             |
| -------------- | ------------------------------------- |
| **Class**      | Wizard (War magic)                    |
| **Level**      | 9                                     |
| **Race**       | [[Gnome]][[Gnome#Rock Gnome\|(Rock)]] |
| **Alignment**  | Neutral                               |
| **Background** | Sage                                  |

--- end-multi-column


# Stats

|                           HP                           |                               AC                                | Speed | Initiative |
| :----------------------------------------------------: | :-------------------------------------------------------------: | :---: | :--------: |
| `$=((dv.current().CON-10)/2 + 4) * dv.current().Level` | `$=(dv.current().MageArmor ? "16+2 ([[Mage Armor]])" : "14+2")` | 25 ft |     +7     |

|Hit Dice|Proficiency Bonus|Temp HP|
|:-:|:-:|:-:|
|9d6|+4|0|

| Senses                 | #   |
| ---------------------- | --- |
| **Passive Perception** | 11  |

---

## Abilities

### Abilities

|STR|DEX|CON|INT|WIS|CHA||
|:-:|:-:|:-:|:-:|:-:|:-:|---|
|`=this.STR`|`=this.DEX`|`=this.CON`|`=this.INT`|`=this.WIS`|`=this.CHA`|**Stats**|
|`$=((dv.current().STR - 10)/2 > -1 ? "+" : "") + (dv.current().STR - 10)/2`|`$=((dv.current().DEX - 10)/2 > -1 ? "+" : "") + (dv.current().DEX - 10)/2`|`$=((dv.current().CON - 10)/2 > -1 ? "+" : "") + (dv.current().CON - 10)/2`|`$=((dv.current().INT - 10)/2 > -1 ? "+" : "") + (dv.current().INT - 10)/2`|`$=((dv.current().WIS - 10)/2 > -1 ? "+" : "") + (dv.current().WIS - 10)/2`|`$=((dv.current().CHA - 10)/2 > -1 ? "+" : "") + (dv.current().CHA - 10)/2`|**Modifier**|
|`$=(1+(dv.current().STR - 10)/2 > -1 ? "+" : "") + (1+(dv.current().STR - 10)/2 + (dv.current().SavingThrows.includes("STR") ? dv.current().proficiency : 0))`|`$=(1+(dv.current().DEX - 10)/2 > -1 ? "+" : "") + (1+(dv.current().DEX - 10)/2 + (dv.current().SavingThrows.includes("DEX") ? dv.current().proficiency : 0))`|`$=(1+(dv.current().CON - 10)/2 > -1 ? "+" : "") + (1+(dv.current().CON - 10)/2 + (dv.current().SavingThrows.includes("CON") ? dv.current().proficiency : 0))`|`$=(1+(dv.current().INT - 10)/2 > -1 ? "+" : "") + (1+(dv.current().INT - 10)/2 + (dv.current().SavingThrows.includes("INT") ? dv.current().proficiency : 0))`|`$=(1+(dv.current().WIS - 10)/2 > -1 ? "+" : "") + (1+(dv.current().WIS - 10)/2 + (dv.current().SavingThrows.includes("WIS") ? dv.current().proficiency : 0))`|`$=(1+(dv.current().CHA - 10)/2 > -1 ? "+" : "") + (1+(dv.current().CHA - 10)/2 + (dv.current().SavingThrows.includes("CHA") ? dv.current().proficiency : 0))`|**Saving Throw**|


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

## Gnome
- **Age**: Gnomes mature at the same rate [humans](https://roll20.net/compendium/dnd5e/Human?expansion=34047#content) do, and most are expected to settle down into an adult life by around age 40. They can live 350 to almost 500 years.
- **Alignment**: Gnomes are most often [good](https://roll20.net/compendium/dnd5e/Rules:Character%20Advancement?expansion=34047#toc_14). Those who tend toward law are sages, engineers, researchers, scholars, investigators, or inventors. Those who tend toward chaos are minstrels, tricksters, wanderers, or fanciful jewelers. Gnomes are good-hearted, and even the tricksters among them are more playful than vicious.
- **Size**: Gnomes are between 3 and 4 feet tall and average about 40 pounds. Your size is Small.
- **Darkvision**: Accustomed to life underground, you have superior vision in dark and dim conditions. You can see in [dim light](https://roll20.net/compendium/dnd5e/Rules:The%20Environment?expansion=34047#toc_3) within 60 feet of you as if it were bright light, and in darkness as if it were dim light. You can’t discern color in darkness, only shades of gray.
- **Gnome Cunning**: You have [advantage](https://roll20.net/compendium/dnd5e/Rules:Ability%20Scores?expansion=34047#toc_2) on all Intelligence, Wisdom, and Charisma saving throws against magic.
## Rock
 - **Artificer's Lore.** Whenever you make an Intelligence (History) check related to magical, alchemical, or technological items, you can add twice your proficiency bonus instead of any other proficiency bonus that may apply.
- **Tinker.** You have proficiency with artisan tools (tinker's tools). Using those tools, you can spend 1 hour and 10 gp worth of materials to construct a Tiny clockwork device (AC 5, 1 hp). The device ceases to function after 24 hours (unless you spend 1 hour repairing it to keep the device functioning), or when you use your action to dismantle it; at that time, you can reclaim the materials used to create it. You can have up to three such devices active at a time. When you create a device, choose one of the following options:
    - _**Clockwork Toy.**_ This toy is a clockwork animal, monster, or person, such as a frog, mouse, bird, dragon, or soldier. When placed on the ground, the toy moves 5 feet across the ground on each of your turns in a random direction. It makes noises as appropriate to the creature it represents.
    - _**Fire Starter.**_ The device produces a miniature flame, which you can use to light a candle, torch, or campfire. Using the device requires your action.
    - _**Music Box.**_ When opened, this music box plays a single song at a moderate volume. The box stops playing when it reaches the song's end or when it is closed.
    - At your DM's discretion, you may make other objects with effects similar in power to these. The [Prestidigitation](https://dnd5e.wikidot.com/spell:prestidigitation) cantrip is a good baseline for such effects.
    - 
## Wizard
- **Spellcasting Ability**: Intelligence is your spellcasting ability for your wizard spells, since you learn your spells through dedicated study and memorization. You use your Intelligence whenever a spell refers to your spellcasting ability. In addition, you use your Intelligence modifier when setting the saving throw DC for a wizard spell you cast and when making an attack roll with one.
- **Ritual Casting**: You can cast a wizard spell as a ritual if that spell has the ritual tag and you have the spell in your spellbook. You don’t need to have the spell prepared.
- **Arcane Recovery**: You have learned to regain some of your magical energy by studying your spellbook. Once per day when you finish a short rest, you can choose expended spell slots to recover. The spell slots can have a combined level that is equal to or less than half your wizard level (rounded up), and none of the slots can be 6th level or higher. For example, if you’re a 4th-level wizard, you can recover up to two levels worth of spell slots. You can recover either a 2nd-level spell slot or two 1st-level spell slots.
## War magic

- **Arcane Deflection**: At 2nd level, you have learned to weave your magic to fortify yourself against harm. When you are hit by an attack or you fail a saving throw, you can use your reaction to gain a +2 bonus to your AC against that attack or a +4 bonus to that saving throw.
- **Tactical Wit**: Starting at 2nd level, your keen ability to assess tactical situations allows you to act quickly in battle. You can give yourself a bonus to your initiative rolls equal to your Intelligence modifier.
- **Power Surge**: Starting at 6th level, you can store magical energy within yourself to later empower your damaging spells. You can store a maximum number of power surges equal to your Intelligence modifier (minimum of one). Whenever you finish a long rest, your number of power surges resets to one. Whenever you successfully end a spell with [Dispel Magic](http://dnd5e.wikidot.com/spell:dispel-magic) or [Counterspell](http://dnd5e.wikidot.com/spell:counterspell), you gain one power surge, as you steal magic from the spell you foiled. If you end a short rest with no power surges, you gain one power surge. Once per turn when you deal damage to a creature or object with a wizard spell, you can spend one power surge to deal extra force damage to that target. The extra damage equals half your wizard level. When you use this feature, you can't cast spells other than cantrips until the end of your next turn.

## Proficiencies

- Drink alchol
- Armor: none
- Weapons: daggers, darts, slings, quarterstaffs, light crossbows
- Tools: none

## Languages

- Common
- Draconic
- Elvish
- Gnomish

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
- **Weapons**: 
	- [[Dagger]]: 1d4 + `$=(dv.current().DEX-10)/2` (x2)
- **Cantrips**: 
	- [[Mage Hand]]
	- [[Shape Water]]
	- [[Fire Bolt]]
	- [[Minor Illusion]]

## Spells
- **Spell save DC** 15 (+7) 
- Cantrips: [[Fire Bolt]], [[Ray of Frost]], [[Minor Illusion]], [[Prestidigitation]], [[Mage Hand]]
- [[Timmy Lannethorn#I-Buc Spells Slots|Spells slots]]
# Equipment

| CP  | SP  | EP  | GP  | PP  |
| :-: | :-: | :-: | :-: | :-: |
|  0  |  0  |  0  |  4  |  0  |

- Weapons: ~~[[Dagger]] x2~~
- [[I-Buc|I-buc📖]] 
- [[Spellbook de rellotges]]
- Arcane focus 📿
- [[Backpack]] 
- Armor: None
# Personality

- Respecta pels marginats
- Pacifista
- **Trastorn evasiu** degut al seu passat. Culpat per la mort de la seva mare i el rebuig que rep pels demés. Sovint detonant en alchol i sexe
- Sap aconseguir l'ajuda dels altres intentant ajuntar els objectius dels demés i propis

## Phrases
- _La ment necessita llibres com l'espasa necessita una pedra d'esmolar si vol mantenir la seva agudesa_
- _Si deixes que s'adonin que les seves paraules et fan mal, mai t'alliberaràs de les burles. Si et posen un malnom, recull-lo i transforma'l en el teu nom_
- _La mort és tan... definitiva, Mentre que la vida és plena de possibilitats_
- _No és fàcil estar borratxo tot el temps. Si no tots ho farien_
- _És difícil posar una corretja a un gos una vegada que li has posat una corretja al cap_
- _No es tracta de què fem, sinó de perquè ho fem_
- _No se'm dóna particularment bé la violència, però sóc bo a convèncer altres perquè siguin violents per mi_
- _Tot és millor amb una mica de vi a la panxa_
- _Gairebé tots els homes prefereixen negar la veritat abans que enfrontar-s'hi_
# Strategy

- Sobreviure

# Background

**Tyrian Lannethorn**, fill més jove de Lord Tiberian Lannethorn, va néixer en una família poderosa i orgullosa, coneguda per les seves terres vastes i les seves influències polítiques. El seu pare, un home alt i imponent, i els seus germans, Celeste i Joran, sempre l’han considerat un fracàs. A diferència dels seus germans, que van heretar la força i l’habilitat per les arts de la guerra, Tyrian era petit, i la seva estatura d’un mighome feia que tothom el veiés com a feble i inútil. Però el que la seva família no va entendre mai va ser que el petit Tyrian era, de fet, el més perillós de tots.

En un món ple de guerres, traïcions i màgia, la seva veritable força no era la força física, sinó la seva ment afilada i la seva connexió amb les arts arcàniques. Des de ben jove, Tyrian va descobrir que la màgia era el seu camí per demostrar el seu valor. Va estudiar sota els millors mestres d'arcans, subratllant les tècniques més complexes de la màgia de control i il·lusió, aprofitant la seva aguda ment i capacitat de lectura d’emocions i situacions.

Malgrat la seva brillantor, les portes de la cort es van tancar per a ell. La seva família, i especialment el seu germà Joran, que desitjava la glòria en el camp de batalla, considerava que un mag tan petit no tenia cap lloc al seu costat. Però Tyrian va aprendre a ser més astut que qualsevol cavaller. Va començar a manipular les subtilitats polítiques de la cort amb un somriure subtil, utilitzant la seva intel·ligència per convèncer als altres, per manipular els esdeveniments des de les ombres.

El seu gran moment va arribar quan el regne es va veure amenaçat per un nou enemic: un governant estranger amb una força militar formidable i un poder màgic desconegut. La seva família, desconcertada i aterrida, va intentar una aliança amb el rei rival. Però Tyrian, amb les seves habilitats màgiques, va veure una oportunitat de redimir-se i salvar el seu nom. Va utilitzar les seves habilitats d'il·lusió i encantament per enganyar l'enemic, convencent-lo que els seus exèrcits eren més nombrosos del que realment eren i que l'aliança amb el regne era una trampa.

Quan el conflicte va arribar a l’extrem, va ser Tyrian qui, amb un conjur astut, va envair els somnis del líder enemic, fent-li veure una visió aterradora d'una traïció interna. El líder va caure en el parany, i amb la seva retirada, el regne va ser salvat. Aquest acte va catapultar Tyrian al reconeixement i la seva família, que abans el menyspreava, va veure finalment el veritable valor que aportava. Però Tyrian sabia que no era la glòria que volia; el que realment desitjava era la llibertat per viure segons les seves pròpies regles.

Ara, Tyrian viatja pel món, buscant més coneixements arcans, utilitzant la seva màgia per defensar els innocents i mantenint sempre un ull sobre les intrigues que es desenvolupen a les corts i els regnes. La seva astúcia i les seves habilitats màgiques el converteixen en un aliat valuós per aquells que el coneixen, però també en un enemic temible per aquells que s’atreveixen a subestimar-lo.

# Current Match


## Current Stats

```meta-bind
INPUT[progressBar(minValue(0), maxValue(54)):currentHp]
```


- **HP**: `INPUT[number:currentHp]` / `$=((dv.current().CON-10)/2 + 4) * dv.current().Level`
- **Temporary Hit Points**: `INPUT[number:TemporaryHp]`
- **Hit Dice**:  `INPUT[number:NumHitDice]`/`=this.Level` (1d6)
- **AC**: `$=(dv.current().MageArmor ? "15 ([[Mage Armor]])" : "13")`
- **Initiative**: +`$=(dv.current().DEX-10)/2 + (dv.current().INT-10)/2`

# Elemental
[[Elementals]]
- ~~HP: 90
- ~~AC: 15

## [[I-Buc|Spells]] Slots
### Level 1
- [x] **Slot 1 Available**
- [ ] **Slot 2 Available**
- [ ] **Slot 3 Available**
- [ ] **Slot 4 Available**
### Level 2
- [ ] **Slot 1 Available**
- [ ] **Slot 2 Available**
- [ ] **Slot 3 Available**
### Level 3
- [x] **Slot 1 Available**
- [ ] **Slot 2 Available**
- [ ] **Slot 3 Available**
### Level 4
- [ ] **Slot 1 Available**
- [ ] **Slot 2 Available**
- [ ] **Slot 3 Available**
### Level 5
- [ ] **Slot 1 Available**


## Conditions
`INPUT[toggle:MageArmor]` Mage Armor
- [ ] **Exhaust** 
- [ ] **Poisoned**
- [ ] **Stunned**
- [ ] **Blinded**
- [ ] **Paralyzed**
- [ ] **Other**: [Other Conditions]

## Notes

