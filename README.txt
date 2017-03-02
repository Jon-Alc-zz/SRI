=============
CS109 Project
=============


=============
Group Members
=============
Jonathan F. Alcantara <- group leader
Enrique Molina
Jared Ono
Sebastian Shelley



=====
Files
=====
Database.cpp/h      - Files for the Database class
Fact.cpp/h          - Files for the Fact class
Family.sri          - Testfile for the SRI program
KnowledgeBase.cpp/h - Files for the KnowledgeBase class
Main.cpp            - File that runs main()
Rule.cpp/h          - Files for the Rule class
RuleBase.cpp/h      - Files for the RuleBase class
test.sri            - Testfile for the SRI program
test2.sri           - Testfile for the SRI program 
Updated-Design.vpp  - The diagram file for the project


=====
Usage
=====

Overview
--------
This SRI system takes input from the user. The user can create 'fact's that hold information, and create 'rule's that act on those facts to create more
information. After, the user can use 'inference' to query the database for info. If necessary, the user can 'drop' facts/rules under a given name. Lastly,
the user can also 'dump' the database into an .sri file that can be 'load'ed for use later on.


Makefile
--------
To compile the files together, make sure that these files are in the folder:
- Database.cpp/h
- Fact.cpp/h
- KnowledgeBase.cpp/h
- Main.cpp
- Rule.cpp/h
- RuleBase.cpp/h
- makefile
If these files are together, you can type 'make' in the command line and hit ENTER. Everything should compile and SRITest should be created, and can be used.


Testfile
--------
There are three test files included:
- Family.sri - This file models the given example in the project file.
- test.sri   - This file tests recursive rules.
- test2.sri  - This file tests three arguments.


Commands
--------

FACT - Create a fact of information
Syntax: fact [[factName]]([[argName1]], [[argName2]])
- factName is the name of the fact
- argName1 is the name of the parent in the fact
- argName2 is the name of the child in the fact

Example: fact Parent(first, second)


RULE - Create a rule that adds a relationship among facts
Syntax: rule [[ruleName]]($[[argName1]], $[[argNameN]]) :- [[operator]] [[factName1]]($[[argName1]], $[[argName2]]) ... [[factNameN]]($argNameN-1, $argNameN)
- ruleName is the name of the rule
- argName1 is the name of the highest/first argument
- argNameN is the name of the lowest/last argument
- operator is the logical operator to use (OR/AND only)
  + For the OR operator, only argName1 and argNameN exist, and all facts must use these arguments.
  + For the AND operator, you can only use two arguments per fact!
- factName1 is the name of the first fact to use in the relationship
- factNameN is the name of the last fact to use in the relationship
- argName2 & argNameN-1 is the name of the arguments in the middle

Notes: Putting the arguments in order is required.
       You can have any number of arguments. If there are facts with differing amounts of arguments, they will also be returned.
       - If you call for three arguments and you have a fact with two, those two will be printed.
       - If you call for two arguments and you have a fact with three, the first two will be printed.
       ... is for if there are multiple facts. 

Examples: rule Example($X, $Y) :- OR A($X, $Y) B($X, $Y) C($X, $Y) D($X, $Y)
	  rule Example($X, $Y, $Z) :- OR A($X, $Y, $Z) B($X, $Y, $Z)
	  rule Example($X, $Y) :- AND A($X, $Z) B($Z, $Y)


INFERENCE - Either query all data under a rule, or copy all data under a rule and paste it under a fact of a given name
Syntax: inference [[ruleName]] {{newFactName}}
- ruleName is the name of an existing rule
- newFactName is the name of the new fact

Examples: inference GrandFather
	  inference GrandFather GF


DROP - Drop all data of a given name in both fact and rule
Syntax: drop [[dataName]]
- dataName is the name of an existing fact or rule

Example: drop father


LOAD - Load from an existing file
Syntax: load [[fileName]]
- fileName is the name of the file

Example: load Family.sri


DUMP - Dump to a file (existing or not)
Syntax: dump [[fileName]]
- fileName is the name of the file

Example: dump example.sri


====
BUGS
====
- You can only use the AND operator with two arguments! A different number will crash the program.