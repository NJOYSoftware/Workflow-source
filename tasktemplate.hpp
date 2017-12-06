#ifndef TASKTEMPLATE_HPP
#define TASKTEMPLATE_HPP

#include <QString>
#include <cstdint>

class TaskTemplate
{
public:
  int_fast32_t idTemplate;
  QString titleTemplate;
  QString textTemplate;

  TaskTemplate(int_fast32_t newId, QString newTitle, QString newText);
};

#endif // TASKTEMPLATE_HPP
