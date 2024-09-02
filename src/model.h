#ifndef MODEL_H
#define MODEL_H

#include <cstring>
#include <ostream>
#include <vector>

#include "system.h"
#include "flow.h"
#include "FlowHandle.h"

class Model
{
public:
    /**
     * @brief Destroy the Model object
     *
     */
    virtual ~Model() {};

    /**
     * @brief Define o tipo vector<Flow *> como vectorFlow
     *
     */
    typedef typename vector<Flow *>::iterator vectorFlow;

    /**
     * @brief Define o tipo vector<System *> como vectorSystem
     *
     */
    typedef typename vector<System *>::iterator vectorSystem;

    /**
     * @brief Get the Id object
     *
     * @return string
     */
    virtual string getId() const = 0;

    /**
     * @brief Set the Id object
     *
     * @param id
     */
    virtual void setId(const string id) = 0;

    /**
     * @brief 
     *
     * @return vectorFlow
     */
    virtual vectorFlow flowBegin() = 0;

    /**
     * @brief 
     *
     * @return vectorFlow
     */
    virtual vectorFlow flowEnd() = 0;

    /**
     * @brief
     *
     * @return int
     */
    virtual int flowSize() = 0;

    /**
     * @brief
     *
     * @return vectorSystem
     */
    virtual vectorSystem systemBegin() = 0;

    /**
     * @brief
     *
     * @return vectorSystem
     */
    virtual vectorSystem systemEnd() = 0;

    /**
     * @brief
     *
     * @return int
     */
    virtual int systemSize() = 0;

    /**
     * @brief
     *
     * @param system
     */
    virtual void add(System *system) = 0;

    /**
     * @brief
     *
     * @param flow
     */
    virtual void add(Flow *flow) = 0;

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    virtual bool remove(System *) = 0;

    /**
     * @brief
     *
     * @return true
     * @return false
     */
    virtual bool remove(Flow *) = 0;

    /**
     * @brief
     *
     */
    virtual void clear() = 0;

    /**
     * @brief
     *
     */
    virtual void show() = 0;

    /**
     * @brief
     *
     * @param initialValue
     * @param time
     * @param increment
     */
    virtual void execute(int initialValue, int time, int increment) = 0;

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
     * @param name
     * @param initialValue
     * @return System*
     */
    virtual System *createSystem(string name, double initialValue) = 0;

    /**
     * @brief Create a Flow object
     *
     * @tparam FLOW_TYPE
     * @param id
     * @param source
     * @param destiny
     * @return Flow*
     */
    template <typename FLOW_TYPE>
    Flow *createFlow(const string &id, System *source, System *destiny)
    {
        Flow *f = new FlowHandle<FLOW_TYPE>(id, source, destiny);
        add(f);
        return f;
    };

    static void add(Model *model);
};

#endif // MODEL_H