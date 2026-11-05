Requirements for Smart Study Room Occupancy Tracker

Expected Product Functionality:
  - 1. Allow the user to record when a person enters or exits a study room
  - 2. Maintain an accurate count of current occupants
  - 3. Prevent occupancy from becoming negative
  - 4. Prevent the count for exceeding maximum room capacity
  - 5. Display current occupancy and room status
  - 6. Save occupancy events to a file
  - 7. Use an LED connected to the Raspberry Pi to indicate when the room is full
  - 8. Support a change to the maximum room capacity

1 - Keep a count variable equaling current occupants. And constant equaling MAX occupants. Function that allows user to add 1 or subtract 1 to count. 

2 - Count variable

3 - If variable < 0 Display Invalid count message. DO NOT UPDATE COUNT IN THIS CASE

4 - If variable > MAX Display Invalid count message. DO NOT UPDATE COUNT IN THIS CASE

5 - Display function that displays the current room count AFTER EVERY UPDATE or IF ASKED TO DISPLAY BY THE USER (so an option in the menu)

6 - 
