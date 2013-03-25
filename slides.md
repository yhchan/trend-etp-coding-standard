# Coding Standard 


---

# Must Read Books

## Books
- Clean Code: A Handbook of Agile Software Craftsmanship
- Refactoring: Improving the Design of Existing Code
- Agile Principles, Patterns, and Practices in C#
- Working Effectively with Legacy Code

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

# 安西教練，我想早點下班
![I-wanna-go-home](http://i.imgur.com/sPTwWlg.jpg)

---

# The Zen of Python - PEP 20

    Beautiful is better than ugly.
    Explicit is better than implicit.
    Simple is better than complex.
    Complex is better than complicated.
    Flat is better than nested.
    Sparse is better than dense.
    Readability counts.
    ...
    If the implementation is hard to explain, it's a bad idea.
    If the implementation is easy to explain, it may be a good idea.
    ...

---

# Keep It Simple, Stupid (KISS)

## Why
- Complexity leads to more errors and greater maintenance effort
- more understandable, more maintainable, more flexible
- Less is More

## How
- Objective-Oriented Analysis and Design
- Design Patterns
- Don't reinvent wheels

---

# Don't Repeat Yourself (DRY)

## Why
- Improve maintainability

## How
- Avoid Copy & Paste
- Refactoring to general functions/classes

---

# Formatting

---

# Tabs or Spaces

## Don't mix Tabs and Spaces (Editor)

![tab-space-mixing-1](http://i.imgur.com/fqlHTc1.png)

---

# Tabs or Spaces

## Don't mix Tabs and Spaces (Diff)

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

# Distance Creates Beauty - Space (1)

## Google C++ Style Guide (condition)

    !cpp
    if (condition) {
      ...
    } else if (...) {
      ...
    } else {
      ...
    }

    if(condition)     // Bad - space missing after IF.
    if (condition){   // Bad - space missing before {.
    if(condition){    // Doubly bad.

---

# Distance Creates Beauty - Space (2)

## Google C++ Style Guide (loop)

    !cpp
    // Good
    for (int i = 0; i < 5; ++i) {
        ...
    }

    //Bad - space missing after semicolon
    for(int i=0;i<5;++i){
        ...
    }
---

# Distance Creates Beauty - Space (3)

## Python PEP 8

    !python
    if x == 4: print x, y; x, y = y, x  // YES
    if x==4:print x,y; x,y=y,x          // NO

    dict['key'] = list[index]           // YES
    dict ['key'] = list [index]         // NO

    spam(1)                             // YES
    spam (1)                            // NO

---

# Function Argument

## On one line if it fits; otherwise, wrap arguments at the parenthesis.

    !cpp
    bool retval = DoSomething(argument1, argument2, argument3);

    bool retval = DoSomething(argument1,
                              argument2,
                              argument3,
                              argument4);

---

# Does too many arguments mean **bad design**?

---

# Long String

## Respect line limit, for example: 80 characters

    !python
    my_very_big_string = """For a long time I used to go to bed early. Sometimes, \
        when I had put out my candle, my eyes would close so quickly that I had not even \
        time to say I’m going to seep."""

    my_very_big_string = (
        "For a long time I used to go to bed early. Sometimes, "
        "when I had put out my candle, my eyes would close so quickly "
        "that I had not even time to say I’m going to sleep"
    )


---

# Naming

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

---

# Functions

---

# Meaningful Functions (1)
- Do one thing in a function
- Keep function **Small**
- Use Polymorphism instead of Switch-case

---

# Meaningful Functions (2)

    !java
    // Bad Example
    void printOwing() {
        Enumeration e = _orders.elements();
        double outstanding = 0.0;

        // print banner
        System.out.println ("**************************");
        System.out.println ("***** Customer Owes ******");
        System.out.println ("**************************");

        // calculate outstanding
        while (e.hasMoreElements()) {
            Order each = (Order) e.nextElement();
            outstanding += each.getAmount();
        }

        //print details
        System.out.println ("name:" + _name);
        System.out.println ("amount" + outstanding);
    }

---

# Meaningful Functions (3)

    !java
    // Better Example
    void printOwing() {
        printBanner();
        outstanding = getOutstanding(outstanding);
        printDetails(outstanding);
    }

    void printBanner() {
        // print banner
        System.out.println ("**************************");
        System.out.println ("***** Customer Owes ******");
        System.out.println ("**************************");
    }
    ...

---

# Output by argument

## Need to consider Exception-Safety

    !cpp
    void generate_numbers_vector_bad(std::vector<int>& vec) {
      vec.clear();
      vec.push_back(1);
      vec.push_back(2);  // If exception is thrown ...
    }

    void generate_numbers_vector_swap(std::vector<int>& vec) {
      std::vector<int> result;
      result.push_back(1);
      result.push_back(2);
      std::swap(vec, result);   // swap is nothrow
    }

---

# Output by return value

## Better Readability

    !cpp
    std::vector<int> generate_numbers_vector_return() {
      std::vector<int> result;
      result.push_back(1);
      result.push_back(2);
      return result;  // RVO or move statement
    }


---

# Pass by value or reference (C++)

## Consider Performance? Read [Want Speed? Pass by Value.][speed]
[speed]: http://cpp-next.com/archive/2009/08/want-speed-pass-by-value/

## Use pass by value in C++11

    !cpp
    // Old Style
    std::vector<std::string>
    sorted2(std::vector<std::string> const& names)
    {
        std::vector<std::string> r(names);        // and explicitly copied
        std::sort(r);
        return r;
    }

    // New Style
    std::vector<std::string>
    sorted(std::vector<std::string> names)
    {
        std::sort(names);
        return ret;
    }

---

# Use if wisely

    !java
    // By unsuccessful case
    // We might introduce new error code in the future
    if (deletePage(page) != E_PERM || deletePage(page) != E_OPEN) {
        // do something
    }

    // By successful case
    if (deletePage(page) == E_OK) {
        // do something
    }

---

# Use Exception over Error Code

    !java
    // Use Error Code
    if (deletePage(page) == E_OK) {
        if (registry.deleteReference(page.name) == E_OK) {
            if (configKeys.deleteKey(page.name.makeKey()) == E_OK){
                logger.log("page deleted");
            } else {
                logger.log("configKey not deleted");
            }
        } else {
            logger.log("deleteReference from registry failed");
        }
    } else {
        logger.log("delete failed");
        return E_ERROR;
    }

---

# Use Exception over Error Code

    !java
    // Exception Style
    try {
        deletePage(page);
        registry.deleteReference(page.name);
        configKeys.deleteKey(page.name.makeKey());
    }
    catch (SomeOtherException e) {
        logger.log(e.getMessage());
    }
    catch (Exception e) {
        logger.log(e.getMessage());
    }

---

# Comment (1)

## Explain Yourself in Code
    !java
    // Check to see if the employee is eligible for full benefits
    if (employee.flags && HOURLY_FLAG && (employee.age > 65)) {
        // do something
    }

    if (employee.isEligibleForFullBenefits()) {
        // do something
    }

## Express your intention
    !python
    def map_async(self, func, iterable, callback=None):
        """
        A variant of the map() method which returns a Greenlet object.

        If callback is specified then it should be a callable which accepts a
        single argument.
        """
        return Greenlet.spawn(self.map_cb, func, iterable, callback)

---

# Comment (2)

## TODO / FIXME
    !python
    # TODO: this is supposed to iterate through all the addresses
    # could use a global dict(hostname, iter)
    # - fix these nasty hacks for localhost, ips, etc.

## Don't comment out your code
- Trust version control

## Javadoc
    !java
    /*
    * @param  url  an absolute URL giving the base location of the image
    * @param  name the location of the image, relative to the url argument
    * @return      the image at the specified URL
    */
    public Image getImage(URL url, String name) {
        try {
            return getImage(new URL(url, name));
        } catch (MalformedURLException e) {
            return null;
        }
    }

---
# Good Object-Oriented Practice
