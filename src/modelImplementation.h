#ifndef MODELIMP_H
#define MODELIMP_H

#include <cstring>
#include <ostream>
#include <vector>

#include "system.h"
#include "model.h"
#include "handleBodySemDebug.h"

class ModelImplementation : public Body
{
protected:
    string id;
    vector<Flow *> flows;
    vector<System *> systems;
    static vector<Model *> models;

private:
    /**
     * @brief Construct a new Model Implementation object
     *
     * @param obj
     */
    ModelImplementation(ModelImplementation &obj);

    /**
     * @brief
     *
     * @param obj
     * @return ModelImplementation&
     */
    ModelImplementation &operator=(const ModelImplementation &obj);

public:
    /**
     * @brief Construct a new Model Implementation object
     *
     */
    ModelImplementation();

    /**
     * @brief Construct a new Model Implementation object
     *
     * @param id
     */
    ModelImplementation(const string id);

    /**
     * @brief Destroy the Model Implementation object
     *
     */
    virtual ~ModelImplementation();

    /**
     * @brief Get the Id object
     *
     * @return string
     */
    string getId() const;

    /**
     * @brief Set the Id object
     *
     * @param id
     */
    void setId(const string id);

    /**
     * @brief
     *
     * @return Model::vectorFlow
     */
    Model::vectorFlow flowBegin();

    /**
     * @brief
     *
     * @return Model::vectorFlow
     */
    Model::vectorFlow flowEnd();

    /**
     * @brief
     *
     * @return int
     */
    int flowSize();

    /**
     * @brief
     *
     * @return Model::vectorSystem
     */
    Model::vectorSystem systemBegin();

    /**
     * @brief
     *
     * @return Model::vectorSystem
     */
    Model::vectorSystem systemEnd();

    /**
     * @brief
     *
     * @return int
     */
    int systemSize();

    /**
     * @brief
     *
     */
    void add(System *);

    /**
     * @brief
     *
     */
    void add(Flow *);

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool remove(System *);

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    bool remove(Flow *);

    /**
     * @brief
     *
     */
    void clear();

    /**
     * @brief
     *
     */
    void show();

    /**
     * @brief
     *
     * @param model
     */
    static void add(Model *model);

    /**
     * @brief
     *
     * @param initialTime
     * @param time
     * @param increment
     */
    virtual void execute(int initialTime, int time, int increment);

    /**
     * @brief Create a Model object
     *
     * @param id
     * @return Model*
     */
    static Model *createModel(string id);

    /**
     * @brief Create a System object
     *
     * @param id
     * @param initialValue
     * @return System*
     */
    System *createSystem(string id, double initialValue);
};

class ModelHandle : public Model, public Handle<ModelImplementation>
{
public:
    ModelHandle() {};

    ModelHandle(string id)
    {
        pImpl_->setId(id);
    };

    virtual ~ModelHandle() {};

    string getId() const
    {
        return pImpl_->getId();
    };

    void setId(const string id)
    {
        pImpl_->setId(id);
    };

    vectorFlow flowBegin()
    {
        return pImpl_->flowBegin();
    };

    vectorFlow flowEnd()
    {
        return pImpl_->flowEnd();
    };

    int flowSize()
    {
        return pImpl_->flowSize();
    };

    vectorSystem systemBegin()
    {
        return pImpl_->systemBegin();
    };

    vectorSystem systemEnd()
    {
        return pImpl_->systemEnd();
    };

    int systemSize()
    {
        return pImpl_->systemSize();
    };

    void add(System *obj)
    {
        pImpl_->add(obj);
    };

    void add(Flow *obj)
    {
        pImpl_->add(obj);
    };

    bool remove(System *obj)
    {
        return pImpl_->remove(obj);
    };

    bool remove(Flow *obj)
    {
        return pImpl_->remove(obj);
    };

    void clear()
    {
        return pImpl_->clear();
    };

    void show()
    {
        return pImpl_->show();
    };

    virtual void execute(int initialTime, int time, int increment)
    {
        return pImpl_->execute(initialTime, time, increment);
    };

    System *createSystem(string id, double initialValue)
    {
        return pImpl_->createSystem(id, initialValue);
    };
};

#endif // MODELIMP_H