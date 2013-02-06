# Coding Standard 

---

# Agenda
- Coding Standard Introduction
- Define Coding Standards
- Well-known Coding Standards
- Tools
- Q & A

---

# Why **Coding Standatd**?
- Consistency
    * Naming
    * Code Structure
- Extensibility
    * Easy to add new features
- Maintainability
    * Easy to understand
    * Easy to debug

---

#General Concept
- Express Intentions
- Explicit is better than implicit
- Use technologies
    * autocomplete
    * refactoring tools
    * jump to definitions

---

# Tabs or Spaces

## Rules of Thumb
- Don't mix Tabs and Spaces (Editor)

![tab-space-mixing-1](http://i.imgur.com/fqlHTc1.png)

---

#Tabs or Spaces

## Rules of Thumb
- Don't mix Tabs and Spaces (Diff)

![tab-space-mixing-2](http://i.imgur.com/7cgpJoZ.png)

---
# Tabs or Spaces

## My Recommendations
- Use spaces in most cases
- Use tabs in the following cases
    * File format restriction (Makefile)
    * Tab preferred code base (Linux Kernel)
- Display tabs and space in your IDE
    * vim -> :set list
---

# Meaningful Variable Naming (1)

## Intention-Revealing Name

    !python
    # Bad
    days = 0  # elapsed time in days

    # Good
    elapsed_time_indays = 0

## Pronounceable Names

    !python
    # Bad
    genymdms = 0

    # Good
    generation_timestamp = 0

---

# Meaningful Variable Naming (2)

## Self-explained variable and constant (**SEARCHABLE**)

    !python
    # Bad
    varaibles = [make_variable(j) for j in xrange(5)]

    # Good
    MAX_VARIABLE = 5
    variables = [make_variable(var) for var in xrange(MAX_VARIABLE)]

---

# Meaningful Variable Naming (3)

## Don't use Hungarian Notation (in most cases)
Changing variable type is painful

    !python
    # Bad
    variable_list = [1, 2, 3, 4, 5]
    variable_tuple = (1, 2, 3, 4, 5)
    variable_collection = CustomCollection([1, 2, 3, 4, 5])

    # Good
    variables = [1, 2, 3, 4, 5]
    variables = (1, 2, 3, 4, 5)
    varaibles = CustomCollection([1, 2, 3, 4, 5])

